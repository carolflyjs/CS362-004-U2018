CFLAGS = -w -fpic -coverage -lm -std=c99

default: randomtests

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

randomadventurer: randomadventurer.c dominion.c rngs.c
	gcc -o randomadventurer -g randomadventurer.c dominion.c rngs.c $(CFLAGS)
	echo "RANDOM TEST: randomadventurer.c:" >> randomadventurer.out
	./randomadventurer > randomadventurer.out
	echo "COVERAGE: randomadventurer.c:" >> randomadventurer.out
	gcov randomadventurer.c >> randomadventurer.out
	gcov dominion.c >> randomadventurer.out
	cat dominion.c.gcov >> randomadventurer.out

randomtests: randomadventurer randomtestcard1 randomtestcard2

clean:
	rm *.gcda *.gcno *.out *.gcov randomtestcard1 randomtestcard2 randomadventurer
