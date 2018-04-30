CC=g++
CFLAGS=-c -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm

all: da1

benchmark: tvector.o tvectorbacketsort.o tvectornonlinersort.o
	$(CC) $(CFLAGS) -lbenchmark -pthread benchmark.cpp
	$(CC) -lbenchmark -pthread benchmark.o tvector.o tvectorbacketsort.o tvectornonlinersort.o -o bench

da1: main.o tvector.o tvectorbacketsort.o tvectornonlinersort.o
	$(CC) main.o tvector.o tvectorbacketsort.o tvectornonlinersort.o -o da1

main.o:
	$(CC) $(CFLAGS) main.cpp

tvector.o:
	$(CC) $(CFLAGS) tvector.cpp

tvectorbacketsort.o: tvector.o
	$(CC) $(CFLAGS) tvectorbacketsort.cpp

tvectornonlinersort.o: tvector.o
	$(CC) $(CFLAGS) tvectornonlinersort.cpp

clean:
	rm -rf *.o
