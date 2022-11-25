//
//  Testing.hpp
//  Assignment5
//

#ifndef Testing_h
#define Testing_h

#include <sstream>
#include <iostream>
#include <iomanip> 

#include "Timer.hpp"

namespace ECE17 {
    
  int doWordsTest(std::istream &anInput) {
    WordAnalyzer theAnalyzer;
    std::stringstream theOutput;

    size_t theResult=theAnalyzer.countWords(anInput,theOutput);
    std::string theStr=theOutput.str();
    std::cout << "Words: " << theResult << " len: "
      << theStr.length() << "\n";
    return theResult ? 0 : -1;
  }

  int doPairsTest(std::istream &anInput) {
    WordAnalyzer theAnalyzer;
    std::stringstream theOutput;
    
    size_t theResult=theAnalyzer.getWordPairs(anInput,theOutput);
    std::string theStr=theOutput.str();
    std::cout << "Pairs: " << theResult << " len: "
      << theStr.length() << "\n";
    
    return theResult ? 0 : -1;
  }

  bool matches(const std::string &aStr1, const std::string &aStr2) {
    std::stringstream theS1(aStr1);
    std::stringstream theS2(aStr2);
    
    std::string theWord1;
    std::string theWord2;
    while(!theS1.eof()) {
      theS1 >> std::skipws >> theWord1;
      theS2 >> std::skipws >> theWord2;
      if(theWord1!=theWord2) return false;
    }

    return true;
  }

  int doCompressTest(std::istream &anInput, const std::string &aString) {
    //first, determine length of the input...
    
    ECE17::Timer theTimer; //let's check how quickly you can do this!...
    theTimer.start();
    
    WordAnalyzer theAnalyzer;
    std::stringstream theOutput1;
    size_t theResult=theAnalyzer.compress(anInput,theOutput1);
    
    if(theResult) {
      std::stringstream theOutput2;
      std::string theCStr=theOutput1.str();
      size_t theLen1=theCStr.size(); //hang on to compressed len...
      //---------------
      std::cout<<theCStr;
      std::cout<<"theLen1: "<<theLen1<<'\n';
      //---------------
      std::stringstream theCompressed(theCStr);
      size_t theDResult=theAnalyzer.decompress(theCompressed,theOutput2);

      std::string theUStr=theOutput2.str();
      size_t theLen2=theUStr.size();
      //---------------
      std::cout<<theUStr<<'\n';
      std::cout<<"theLen2: "<<theLen2<<'\n';
      //---------------
      static const char* theMsgs[]={"FAIL","SUCCESS"};
      std::cout << "Compression " << theMsgs[matches(theUStr,aString)] << "\n";
      std::cout << "Compress ratio: " << std::setprecision(4)
        << (float(theLen1)/float(theLen2))*100 << "\n";
      
      theTimer.stop();
      std::cout << "\nElapsed time: " << std::fixed << theTimer.elapsed() << "\n";
      
      return theDResult ? 0 : -1;
    }

    return -1;
  }

}
#endif /* Testing_h */
