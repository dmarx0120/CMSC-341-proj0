all: mytest.o

mytest.o: mytest.cpp
	g++ -c mytest.cpp -o mytest

clean: rm -rf *o mytest
