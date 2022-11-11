//
//  LinkedListTest.hpp
//  Assignment4
//

#ifndef LinkedListTest_h
#define LinkedListTest_h

#include <iostream>
#include <sstream>
#include <list>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
//
    #include "LinkedList.hpp"



  //------------------------------------------------------

  const int kNoErrorsDetected = 0;
  const int kFindFailure = 100;
  const int kAppendFailure = 200;
  const int kInsertFailure = 300;
  const int kRemoveFailure = 400;
  const int kVisitorFailure = 500;

  //------------------------------------------------------

  using DataType = float;
  using ListType = ECE17::LinkedList<DataType>;
  using STDListType = std::list<DataType>;

  bool matches(const ListType &aList1,  const STDListType &aList2) {
    auto *theNode=aList1.first();
    for(auto theItem : aList2) {
      if(theItem!=theNode->value) {
        return false;
      }
      theNode=theNode->next;
    }
    return true;
  }

  bool appendItem(DataType aValue, ListType &aList, STDListType &aSTDList) {
    aSTDList.push_back(aValue);
    aList.append(aValue);
    return matches(aList, aSTDList);
  }

  int doAppendAndFindTests() {
    { //we put inside a nested block to do leak test...
      ECE17::LinkedList<DataType> theList; //empty
      std::list<DataType> theSTDList;
        
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

  bool insertItem(DataType aValue, DataType afterValue,
                  ListType &aList, STDListType &aSTDList) {

    auto theIter = std::find(aSTDList.begin(), aSTDList.end(), afterValue);
    theIter++;
    aSTDList.insert(theIter, aValue);

    auto *theFound=aList.find(afterValue);
    aList.insertAfter(aValue, theFound);
    return matches(aList, aSTDList);
  }

  int doInsertTests() {
    { //we put inside a nested block to do leak test...
      ListType theList; //empty
      STDListType theSTDList;

      //insert into empty list...
      STDListType::iterator theIter = theSTDList.begin();
      theSTDList.insert(theIter, 100);
      theList.insertAfter(100);

      //insert into the back...
      if(!insertItem(200, 100, theList, theSTDList)) {
        return kInsertFailure;
      }

      //insert into middle
      if(!insertItem(300, 100, theList,theSTDList)) {
        return kInsertFailure;
      }
          
    }
    return kNoErrorsDetected;
  }

  bool removeItem(DataType aValue, ListType &aList, STDListType &aSTDList) {
    aSTDList.remove(aValue);
    delete aList.remove(aValue);
    return matches(aList,aSTDList);
  }

  int doRemoveTests() {
    { //we put inside a nested block to do leak test...
      ListType theList; //empty
      STDListType theSTDList;
      
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

    return kNoErrorsDetected;
  }

  //------------------------------------------------------

  enum class Ops {append=0, insert, remove, find};

  int doRandomTest() {
    {
      std::srand((unsigned int)time(nullptr));//random # seed...

      ListType theList; //empty
      STDListType theSTDList;
      int theCurrentValue=0;

      for(theCurrentValue=1;theCurrentValue<3;theCurrentValue++) {
        appendItem(theCurrentValue,theList,theSTDList);
      }

      STDListType::iterator theIter;
      
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

  class PrintVisitor : public ListType::INodeVisitor {
  public:
    PrintVisitor(std::ostream &anOutput) : output(anOutput) {}
    virtual void visit(const ListType::Node &aNode) {
      output << aNode.value;
    }
    std::ostream &output;
  };

  //------- visitor test ---------------------
  int doVisitorTest() {
    ListType theType;
    theType.append(100);
    theType.append(200);
    theType.append(300);
    std::stringstream theOutput;
    PrintVisitor thePrinter(theOutput);
    theType.visitWith(thePrinter);
    if("100200300"!=theOutput.str()) {
      std::cout << "Visitor failed\n";
      return kVisitorFailure;
    }
    return 0;
  }



#endif /* LinkedListTest_h */
