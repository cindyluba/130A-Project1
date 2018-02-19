CXX=g++

CXXFLAGS= -std=c++17 -Wall -g

all: main

main: main.o bst.o hashTable.o
	g++ -o main main.o bst.o hashTable.o -lstdc++fs

main.o: main.cpp

bst.o: bst.cpp

hashTable.o: hashTable.cpp

clean:
	rm -rf *.o main output.txt
