CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o interface.o
	gcc -c dominion.c -g rngs.o interface.o $(CFLAGS)

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

randtesta: tests/randomtestadventurer.c dominion.o rngs.o interface.o
	gcc -o randtestadventurer tests/randomtestadventurer.c -g dominion.o interface.o rngs.o $(CFLAGS)

randtestc1: tests/randomtestcard1.c dominion.o rngs.o
	gcc -o randtestcard1 tests/randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randtestc2: tests/randomtestcard2.c dominion.o rngs.o interface.o
	gcc -o randtestcard2 tests/randomtestcard2.c -g dominion.o interface.o rngs.o $(CFLAGS)

randtestex: tests/extrarandomtest.c dominion.o rngs.o
	gcc -o extrarandomtest tests/extrarandomtest.c -g dominion.o rngs.o $(CFLAGS)

buildtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: buildtests playdom
	./unittest1 >> unittestresults.out
	echo "FUNCTION COV OF UT1" >> utresults/utest1.out
	gcov -f unittest1.c >> utresults/utest1.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	echo "Testing: unittest1.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "FUNCTION COV OF UT2" >> utresults/utest2.out
	gcov -f unittest2.c >> utresults/utest2.out
	echo "GCOV AFTER 2 TESTS" >> unittestresults.out
	echo "Testing: unittest2.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "FUNCTION COV OF UT3" >> utresults/utest3.out
	gcov -f unittest3.c >> utresults/utest3.out
	echo "GCOV AFTER 3 TESTS" >> unittestresults.out
	echo "Testing: unittest3.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "FUNCTION COV OF UT4" >> utresults/utest4.out
	gcov -f unittest4.c >> utresults/utest4.out
	echo "GCOV AFTER 4 TESTS" >> unittestresults.out
	echo "Testing: unittest4.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "FUNCTION COV OF CARD 1" >> utresults/card1.out
	gcov -f cardtest1.c >> utresults/card1.out
	echo "GCOV AFTER 5 TESTS" >> unittestresults.out
	echo "Testing: cardtest1.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "FUNCTION COV OF CARD 2" >> utresults/card2.out
	gcov -f cardtest2.c >> utresults/card2.out
	echo "GCOV AFTER 6 TESTS" >> unittestresults.out
	echo "Testing: cardtest2.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "FUNCTION COV OF CARD 3" >> utresults/card3.out
	gcov -f cardtest3.c >> utresults/card3.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	echo "Testing: cardtest3.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "FUNCTION COV OF CARD 4" >> utresults/card4.out
	gcov -f cardtest4.c >> utresults/card4.out
	echo "GCOV AFTER 8 TESTS" >> unittestresults.out
	echo "Testing: cardtest4.c" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 2 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randcardtests: randtesta randtestc1 randtestc2 randtestex
	./randtestadventurer 42 >> rtresults/randomtestadventurer.out
	echo "GCOV OF RANDOM TESTING: ADVENTURER" >> rtresults/randomtestadventurer.out
	gcov -f randomtestadventurer.c >> rtresults/randomtestadventurer.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestadventurer.out
	gcov dominion.c >> rtresults/randomtestadventurer.out
	./randtestcard1  42>> rtresults/randomtestcard1.out
	echo "GCOV OF RANDOM TESTING: CUTPURSE" >> rtresults/randomtestcard1.out
	gcov -f randomtestcard1.c >> rtresults/randomtestcard1.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestcard1.out
	gcov dominion.c >> rtresults/randomtestcard1.out
	./randtestcard2 42 >> rtresults/randomtestcard2.out
	echo "GCOV OF RANDOM TESTING: SMITHY" >> rtresults/randomtestcard2.out
	gcov -f randomtestcard2.c >> rtresults/randomtestcard2.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestcard2.out
	gcov dominion.c >> rtresults/randomtestcard2.out

randadv: randtesta 
	./randtestadventurer 42 >> rtresults/randomtestadventurer.out
	echo "GCOV OF RANDOM TESTING: ADVENTURER" >> rtresults/randomtestadventurer.out
	gcov -f randomtestadventurer.c >> rtresults/randomtestadventurer.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestadventurer.out
	gcov dominion.c >> rtresults/randomtestadventurer.out

randc1: randtestc1
	./randtestcard1  42>> rtresults/randomtestcard1.out
	echo "GCOV OF RANDOM TESTING: CUTPURSE" >> rtresults/randomtestcard1.out
	gcov -f randomtestcard1.c >> rtresults/randomtestcard1.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestcard1.out
	gcov dominion.c >> rtresults/randomtestcard1.out

randc2: randtestc2
	./randtestcard2 42 >> rtresults/randomtestcard2.out
	echo "GCOV OF RANDOM TESTING: SMITHY" >> rtresults/randomtestcard2.out
	gcov -f randomtestcard2.c >> rtresults/randomtestcard2.out
	echo "GCOV OF DOMINION" >> rtresults/randomtestcard2.out
	gcov dominion.c >> rtresults/randomtestcard2.out

testdominion: dominion.o testdominion.c interface.o
	gcc -o testdominion testdominion.c -g dominion.o interface.o rngs.o $(CFLAGS)

testdominion.out: testdominion
	./testdominion 42 >> testdominion.out
	echo "GCOV OF RANDOM TESTER -- 1 RUN" >> testdominion.out
	gcov testdominion.c >> testdominion.out
	echo "GCOV OF DOMINION" >> testdominion.out
	gcov dominion.c >> testdominion.out 

all: playdom player buildtests randtesta randtestc1 randtestc2 testdominion

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randtestadventurer randtestcard1 extrarandomtest randtestcard2 randadv randc1 randc2 player.exe testInit testInit.exe *.out *.gcov *.gcda *.gcno *.so *.a *.dSYM
