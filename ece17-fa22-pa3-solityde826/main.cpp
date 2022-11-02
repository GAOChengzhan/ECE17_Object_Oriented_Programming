//
//  main.cpp
//

#include <iostream>
#include "LinkedList.hpp"
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

//------------------------------------------------------

const int kNoErrorsDetected = 0;
const int kFindFailure = 100;
const int kAppendFailure = 200;
const int kInsertFailure = 300;
const int kRemoveFailure = 400;
const int kMemoryLeak = 600;

//------------------------------------------------------

bool matches(const ECE17::LinkedList aList1, const std::list<int> &aList2) {
  ECE17::Node *theNode = aList1.first();
  for(auto theItem : aList2) {
    if(theItem!=theNode->value) {
      return false;
    }
    theNode=theNode->next;
  }
  return true;
}

bool appendItem(int aValue, ECE17::LinkedList &aList, std::list<int> &aSTDList) {
  aSTDList.push_back(aValue);
  aList.append(aValue);
  return matches(aList, aSTDList);
}

int doAppendAndFindTests() {
  { //we put inside a nested block to do leak test...
    ECE17::LinkedList theList; //empty
    std::list<int> theSTDList;
    if(!appendItem(100,theList,theSTDList)) {
      return kAppendFailure;
    }
    if(!appendItem(200,theList,theSTDList)) {
      return kAppendFailure;
    }
    auto *theFound=theList.find(200);
    if(!theFound ) {
      std::cout << "Find Failed\n";
      return kFindFailure;
    }

  }
  return kNoErrorsDetected;
}

bool insertItem(int aValue, int afterValue,
                ECE17::LinkedList &aList, std::list<int> &aSTDList) {

  auto theIter = std::find(aSTDList.begin(), aSTDList.end(), afterValue);
  theIter++;
  aSTDList.insert(theIter, aValue);

  auto *theFound=aList.find(afterValue);
  aList.insertAfter(aValue, theFound);
  return matches(aList, aSTDList);
}

int doInsertTests() {
  { //we put inside a nested block to do leak test...
    ECE17::LinkedList theList; //empty
    std::list<int> theSTDList;

    //insert into empty list...
    std::list<int>::iterator theIter = theSTDList.begin();
    theSTDList.insert(theIter, 100);
    theList.insertAfter(100);

    //insert into the back...
    if(!insertItem(200, 100, theList,theSTDList)) {
      return kInsertFailure;
    }

    //insert into middle
    if(!insertItem(300, 100, theList,theSTDList)) {
      return kInsertFailure;
    }
        
  }
  return kNoErrorsDetected;
}

bool removeItem(int aValue, ECE17::LinkedList &aList, std::list<int> &aSTDList) {
  aSTDList.remove(aValue);
  delete aList.remove(aValue);
  return matches(aList,aSTDList);
}

int doRemoveTests() {
  { //we put inside a nested block to do leak test...
    ECE17::LinkedList theList; //empty
    std::list<int> theSTDList;
    
    for(int i=1;i<5;i++) {
      theSTDList.push_back(100*i);
      theList.append(100*i);
    }
      
    int theValues[]={100,300,400,200};
    for(int theValue : theValues) {
      if(!removeItem(theValue, theList, theSTDList)) {
        return kRemoveFailure;
      }
    }
  }

  return kNoErrorsDetected;
}

int doBasicTest() {
    
  if(int theResult1=doAppendAndFindTests()) {
    std::cout << "Append Tests Failed\n";
    return theResult1;
  }
  if(int theResult2=doInsertTests()) {
    std::cout << "Insert Tests Failed\n";
    return theResult2;
  }
  if(int theResult3=doRemoveTests()) {
    std::cout << "Remove Tests Failed\n";
    return theResult3;
  }
  if(ECE17::Node::nodeCount) {
    std::cout << "You leaked!\n";
    return kMemoryLeak;
  }
  
  return kNoErrorsDetected;
}

//------------------------------------------------------

enum class Ops {append=0, insert, remove, find};

int doRandomTest() {
  {
    std::srand((unsigned int)time(nullptr));//random # seed...

    ECE17::LinkedList theList; //empty
    std::list<int> theSTDList;
    int theCurrentValue=0;

    for(theCurrentValue=1;theCurrentValue<3;theCurrentValue++) {
      appendItem(theCurrentValue,theList,theSTDList);
    }

    std::list<int>::iterator theIter;
    for(int i=0;i<25000;i++) {
      Ops theOp = Ops(rand() % 4);
      switch(theOp) {
        case Ops::append:
          if(!appendItem(++theCurrentValue,theList,theSTDList)) {
            std::cout << "Append Failed\n";
            return kAppendFailure;
          }
          break;
          
        case Ops::insert:
          if(theSTDList.size()>4) {
            int theRand=rand() % theCurrentValue;
            theIter = std::find(theSTDList.begin(), theSTDList.end(), theRand);
            if(theIter != theSTDList.end()) { //found it...
              if(!insertItem(++theCurrentValue, *theIter, theList,theSTDList)) {
                std::cout << "Insert Failed\n";
                return kAppendFailure;
              }
            }
          }
          break;
          
        case Ops::remove:
          if(theSTDList.size()>4) {
            int theRand=rand() % theCurrentValue;
            theIter = std::find(theSTDList.begin(), theSTDList.end(), theRand);
            if(theIter != theSTDList.end()) { //found it...
              if(!removeItem(*theIter, theList,theSTDList)) {
                std::cout << "Remove Failed\n";
                return kAppendFailure;
              }
            }
          }
          break;
          
        case Ops::find:
          if(theList.size()>100000) {
            int theRand=rand() % theCurrentValue;
            theIter = std::find(theSTDList.begin(), theSTDList.end(), theRand);
            if(theIter != theSTDList.end()) { //found it...
              auto theNode=theList.find(theRand);
              if(theNode->value!=*theIter) return kFindFailure;
            }
          }
          break;
          
      } //switch
    }
  }
  return kNoErrorsDetected;
}

//------------------------------------------------------

int main(int argc, const char * argv[]) {
  // insert code here...
  if(argc>1) {
    std::string temp(argv[1]);
    if("compile"==temp) {
      std::cout << "Passed Compile Test\n";
    }
    else if("basic"==temp) {
      if(!doBasicTest()) {
        std::cout << "Passed Basic Test\n";
      }
    }
    else if ("random"==temp) {
      if(!doRandomTest()) {
        std::cout << "Passed Random Test\n";
      }
    }
    return 0;
  }
  
  //STUDENT -- add your own additional tests here...
  doBasicTest();
  return 0;
}
