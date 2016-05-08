CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest1: tests/unittest1.c dominion.o rngs.o
	gcc -o unittest1 tests/unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: tests/unittest2.c dominion.o rngs.o
	gcc -o unittest2 tests/unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: tests/unittest3.c dominion.o rngs.o
	gcc -o unittest3 tests/unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: tests/unittest4.c dominion.o rngs.o
	gcc -o unittest4 tests/unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: tests/cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 tests/cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: tests/cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 tests/cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: tests/cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 tests/cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: tests/cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 tests/cardtest4.c -g dominion.o rngs.o $(CFLAGS)

buildtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: buildtests playdom
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER 2 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER 3 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "GCOV AFTER 4 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER 5 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER 6 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER 8 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 2 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe unittestresults.out *.gcov *.gcda *.gcno *.so *.a *.dSYM
