CFLAGS = -w -fpic -coverage -lm -std=c99

default: unittestresults.out randomtests

unittestresults.out: unittest1.c unittest2.c dominion.c rngs.c
	echo "Result for running tests:" > unittestresults.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	unittest1 >> unittest1.out
	gcov dominion.c >> unittest1.out
	cat dominion.c.gcov >> unittest1.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	unittest2 >> unittest2.out
	gcov dominion.c >> unittest2.out
	cat dominion.c.gcov >> unittest2.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	unittest3 >> unittest3.out
	gcov dominion.c >> unittest3.out
	cat dominion.c.gcov >> unittest3.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
	unittest4 >> unittest4.out
	gcov dominion.c >> unittest4.out
	cat dominion.c.gcov >> unittest4.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
	cardtest1 >> cardtest1.out
	gcov dominion.c >> cardtest1.out
	cat dominion.c.gcov >> cardtest1.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c $(CFLAGS)
	cardtest2 >> cardtest2.out
	gcov dominion.c >> cardtest2.out
	cat dominion.c.gcov >> cardtest2.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c $(CFLAGS)
	cardtest3 >> cardtest3.out
	gcov dominion.c >> cardtest3.out
	cat dominion.c.gcov >> cardtest3.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.c rngs.c $(CFLAGS)
	cardtest4 >> cardtest4.out
	gcov dominion.c >> cardtest4.out
	cat dominion.c.gcov >> cardtest4.out

randomtestcard1: randomtestcard1.c dominion.c rngs.c
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	echo "RANDOM TEST: randomtestcard1.c:" >> randomtestcard1.out
	./randomtestcard1 > randomtestcard1.out
	echo "COVERAGE: randomtestcard1.c:" >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.c rngs.c
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	echo "RANDOM TEST: randomtestcard2.c:" >> randomtestcard2.out
	./randomtestcard2 > randomtestcard2.out
	echo "COVERAGE: randomtestcard2.c:" >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	echo "RANDOM TEST: randomatestdventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer > randomtestadventurer.out
	echo "COVERAGE: randomatestdventurer.c:" >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtests: randomtestadventurer randomtestcard1 randomtestcard2

clean:
	rm *.gcda *.gcno *.out *.gcov randomtestcard1 randomtestcard2 randomtestadventurer
