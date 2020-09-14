CXX=g++
CXXFLAGS=-Wall

all: mytest.o

mytest.o: mytest.cpp
	$(CXX) $(CXXFLAGS) mytest.cpp -o mytest.out

clean: rm -rf *o mytest.out
