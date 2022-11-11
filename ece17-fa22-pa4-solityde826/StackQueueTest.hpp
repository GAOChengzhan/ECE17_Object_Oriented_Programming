//
//  StackQueueTest.hpp
//  Assignment4
//


#ifndef StackQueueTest_h
#define StackQueueTest_h

#include <stack>
#include <queue>
#include "stack.hpp"
#include "queue.hpp"

using namespace ECE17; 

  const int kStackFailure = 1000;
  const int kQueueFailure = 1005;
  const int kExceptionExpected = 1100;
  const int kNoErrorsFound = 0;

  int doStackTest() {
    Stack<int> theStack;
    std::stack<int> theSTDStack;
    
    theStack.push(100);
    theStack.push(200);
    theStack.push(300);

    theSTDStack.push(100);
    theSTDStack.push(200);
    theSTDStack.push(300);
      
    for(int i=0;i<3;i++) {
      int i1=theSTDStack.top();
      int i2=theStack.peek();
      if(i1==i2) {
        theSTDStack.pop();
        theStack.pop();
      }
      else {
        std::cout << "Stack error\n";
        return kStackFailure;
      }
    }
    
    //test the exception hander...
    try {
      theStack.peek(); //this should fail...
    }
    catch(...) {
      return kNoErrorsFound;
    }
    return kExceptionExpected;
  }

  int doQueueTest() {
    Queue<int> theQueue;
    std::queue<int> theSTDQueue;
    
    theQueue.push(100);
    theQueue.push(200);
    theQueue.push(300);

    theSTDQueue.push(100);
    theSTDQueue.push(200);
    theSTDQueue.push(300);
      
    for(int i=0;i<3;i++) {
      if(theSTDQueue.back()!=theQueue.back()) {
        std::cout << "Queue error\n";
        return kQueueFailure;
      }
      
      int f1=theSTDQueue.front();
      int f2=theQueue.front();
      if(f1==f2) {
        theSTDQueue.pop();
        theQueue.pop();
      }
      else {
        std::cout << "Queue error\n";
        return kQueueFailure;
      }
    }
    
    //test the exception hander...
    try {
      theQueue.front(); //this should fail...
    }
    catch(...) {
      return kNoErrorsFound;
    }
    return kExceptionExpected;
  }



#endif /* StackQueueTest_h */
