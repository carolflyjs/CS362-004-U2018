CFLAGS = -w -fpic -coverage -lm -std=c99

default: tests.out


tests.out: unittest1.c unittest2.c dominion.c rngs.c
	echo "Result for running tests:" > tests.out
	
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	unittest1 >> tests.out
	gcov dominion.c >> tests.out
		
	echo "unittest2.c:" >> tests.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	unittest2 >> tests.out
	gcov dominion.c >> tests.out
	
	echo "unittest3.c:" >> tests.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	unittest3 >> tests.out
	gcov dominion.c >> tests.out
	
	echo "unittest4.c:" >> tests.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
	unittest4 >> tests.out
	gcov dominion.c >> tests.out


clean:
	rm *.gcda *.gcno *.out 
