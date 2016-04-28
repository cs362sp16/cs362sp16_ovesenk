CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

test_helpers.o: test_helpers.h test_helpers.c
	gcc -c test_helpers.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

unittest2: unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

unittest3: unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

unittest4: unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

cardtest1: cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

cardtest3: cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

cardtest4: cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o test_helpers.o $(CFLAGS)

unittest: unittest1 unittest2 unittest3 unittest4

unittestout:
	echo >> unittestresult.out
	unittest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	unittest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	unittest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	unittest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

cardtest: cardtest1 cardtest2 cardtest3 cardtest4

cardtestout:
	cardtest1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cardtest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cardtest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

#cover:
#	gcov dominion.c >> unittestresult.out
#	echo >> unittestresult.out

all: playdom player

test: test_helpers.o playdom player unittest cardtest

unittestresult.out: test unittestout cardtestout

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
