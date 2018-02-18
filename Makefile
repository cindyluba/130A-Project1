CXX=g++

CXXFLAGS= -std=c++17 -Wall -g

LDFLAGS=-lstdc++fs

BINARIES=main node bst

all: ${BINARIES}

clean:
	/bin/rm -f *.o ${BINARIES}
