CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: test_naive.o test_backtracking.o test_greedy.o test_Christofides.o

run-best:
	./test4

run-p1:
	./test1

run-p2:
	./test2

run-p3:
	./test3

run-p4:
	./test4

tsp_naive.o: tsp_naive.cpp
	g++ tsp_naive.cpp -c $(CFLAGS)

test_naive.o: test_naive.cpp tsp_naive.o
	g++ tsp_naive.o test_naive.cpp -o test1 $(CFLAGS)

tsp_back.o: tsp_back.cpp
	g++ tsp_back.cpp -c $(CFLAGS)

test_backtracking.o: test_backtracking.cpp tsp_back.o
	g++ tsp_back.o test_backtracking.cpp -o test2 $(CFLAGS)

tsp_greedy.o: tsp_greedy.cpp
	g++ tsp_greedy.cpp -c $(CFLAGS)

test_greedy.o: test_greedy.cpp tsp_greedy.o
	g++ tsp_greedy.o test_greedy.cpp -o test3 $(CFLAGS)

tsp_Christofides.o: tsp_Christofides.cpp
	g++ tsp_Christofides.cpp -c $(CFLAGS)

test_Christofides.o: test_Christofides.cpp tsp_Christofides.o
	g++ test_Christofides.cpp tsp_Christofides.o -o test4 $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test3 test4 test.in test.out
	rm -rf tests_Christofides/*.out

