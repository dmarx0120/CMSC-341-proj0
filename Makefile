all: mytest.o

mytest.o: mytest.cpp
	g++ -c mytest.cpp -o mytest.out

clean: rm -rf *o test