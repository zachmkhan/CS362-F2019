CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

test: dominion.o interface.o randomtestcard1.c
	gcc -o test randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)

test2: dominion.o randomtestcard2.c
	gcc -o test2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

test3: dominion.o randomtestcard3.c
	gcc -o test3 randomtestcard3.c -g dominion.o rngs.o $(CFLAGS)

unit: dominion.o unit1.c
	gcc -o unit unit1.c -g dominion.o rngs.o $(CFLAGS)

unit2: dominion.o unit2.c
	gcc -o unit2 unit2.c -g dominion.o rngs.o $(CFLAGS)

randomtestresults: test test2 test3
	#Adapteed from Josh Hash on Piazza
	make test
	make test2
	make test3
	make unit
	make unit2
	clear
	./unit >> randomtestresults.out
	./unit2 >> randomtestresults.out
	./test >> randomtestresults.out
	./test2 >> randomtestresults.out
	./test3 >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> unittestresults.out

clean:
	rm -f *.o unit.exe unit unit2.exe unit2 test3 test3.exe example.exe example test.exe test test2.exe test2 player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
