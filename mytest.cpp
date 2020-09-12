//File:		mytest.cpp
//Project:	CMSC 341 Project 0, Fall 2020
//Author:	Derek Marx
//Date:		9/3/2020
//Section:	03
//E - mail: dmarx1@umbc.edu

//Project description

#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    //define source queue intQueue
    Queue<int> intQueue;

    //Load intQueue
    for (int i = 0; i < 11; i++)
    {
        intQueue.enqueue(i);
    }

    //Test1: Check that copy is made ----------------------------------------------------------------------------------.

    cout << "Test 1: ----------------------------------------------------" << endl;
    //call copy constructor to craete intQueue2
    Queue<int> intQueue2 = intQueue;
    cout << "Contents of intQueue:" << endl;
    intQueue.dump();
    cout << "Contents of intQueue2:" << endl;
    intQueue2.dump();
    cout << endl;

    //Test2: Check that copy is deep ------------------------------------------------------------------------------------.

    cout << "Test 2: ----------------------------------------------------" << endl;
    //modify intQueue2 whithout changing intQueue
    intQueue2.dequeue();
    //display contents of both queues
    cout << "Contents of intQueue (source queue): " << endl;
    intQueue.dump();
    cout << "Contents of intQueue2 after dequeueing: " << endl;
    intQueue2.dump();
    cout << endl;

    //Test3: Checking edge cases ------------------------------------------------------------------------------------------.

    cout << "Test 3: ----------------------------------------------------" << endl;
    //Check functionality if source queue is empty.
    //clear intQueue (source queue).
    while (!intQueue.empty())
    {
        intQueue.dequeue();
    }
    //modify intQueue2 by dequeueing.
    intQueue2.dequeue();
    //display contents of both queues
    cout << "Contents of empty intQueue (source queue): " << endl;
    intQueue.dump();
    cout << "Contents of intQueue2 that has now been dequeued twice." << endl;
    intQueue2.dump();
    cout << endl;

    //Checking ecxeption handling on head() function on an empty queue.
    cout << "Checking head() function on an empty queue (intQueue):" << endl;
    try
    {
        intQueue.head();
    }
    catch (range_error &e)
    {
        cout << e.what() << endl;
    }
    cout << endl;

    //Checking exception handling on dequeue() function on an empty queue.
    cout << "Checking dequeue() function on an empty queue:" << endl;
    try
    {
        intQueue.dequeue();
    }
    catch (range_error &e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    
    //Test 4: test for guarding against self-assignment ---------------------------------------------------------------------.

    cout << "Test 4: Checking for guarding against self-assignment: ------------------------------------------------" << endl;
    try
    {
        intQueue2 = intQueue2;
    }
    //catch excpetion if self-assigning or assigning to empty queue.
    catch (const char* error)
    {
        cout << error << endl;
    }

    return 0;
}