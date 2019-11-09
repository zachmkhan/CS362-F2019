#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char c[33] = "abcdefghijklmnopqrstuvwxyz[({ })]";
    int num = (rand() % (32 - 0 + 1)) + 0; 
    return c[num];
}

char *inputString()
{
    // TODO: rewrite this function
    char s[6] = "";
    char c[26] = "abcdefghijklmnopqrstuvwxyz";

    s[0] = c[(rand() % (25 - 0 + 1)) + 0];
    s[1] = c[(rand() % (25 - 0 + 1)) + 0];
    s[2] = c[(rand() % (25 - 0 + 1)) + 0];
    s[3] = c[(rand() % (25 - 0 + 1)) + 0];
    s[4] = c[(rand() % (25 - 0 + 1)) + 0];
    //s[5] = '\0';
    return s;
}

void testme()
{
  //https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      //https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
      end = clock();
      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
      printf("fun() took %f seconds to execute \n", cpu_time_used);

      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
