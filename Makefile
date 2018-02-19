<<<<<<< HEAD
# CXX=g++

# CXXFLAGS= -std=c++17 -Wall -g

# all: main

# main: main.o bst.o
# 	g++ -o main main.o bst.o -lstdc++fs

# main.o: main.cpp

# bst.o: bst.cpp

# clean:
# 	rm -rf *.o main sorted_output.txt

all: main

main: 
	g++ -std=c++17 main.cpp hashTable.cpp node.cpp bst.cpp -o main

clean: rm main
=======
CXX=g++

CXXFLAGS= -std=c++17 -Wall -g

all: main

main: main.o bst.o hashTable.o
	g++ -o main main.o bst.o hashTable.o -lstdc++fs

main.o: main.cpp

bst.o: bst.cpp

hashTable.o: hashTable.cpp

clean:
	rm -rf *.o main sorted_output.txt
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
