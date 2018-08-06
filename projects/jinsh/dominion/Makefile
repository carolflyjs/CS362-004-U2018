CFLAGS = -Wall -fpic -coverage -lm

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

randomtestadventurer: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	echo "RANDOM TEST: randomtestadventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer > randomtestadventurer.out
	echo "COVERAGE: randomtestadventurer.c:" >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtests: randomtestadventurer randomtestcard1 randomtestcard2


clean:
	rm -f *.o randomtestcard1 randomtestcard2 randomtestadventurer *.gcov *.gcda *.gcno
