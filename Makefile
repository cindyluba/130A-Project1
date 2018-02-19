CXX=g++

CXXFLAGS= -std=c++17 -Wall -g

all: main

main: main.o bst.o
	g++ -o main main.o bst.o -lstdc++fs

main.o: main.cpp

bst.o: bst.cpp

clean:
	rm -rf *.o main
