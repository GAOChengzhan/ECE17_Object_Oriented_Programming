//
//  main.cpp
//  Assignment5
//


#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

#include "WordAnalyzer.hpp"
#include "Testing.hpp"

size_t readFile(const std::string &aPath, std::string &aContents) {
  std::ifstream theFile(aPath);
  std::stringstream theStream;
  theStream << theFile.rdbuf(); //read the file
  aContents = theStream.str(); //str holds the content of the file
  return aContents.size();
}

int main(int argc, const char * argv[]) {
  if(argc>1) {
    std::string temp(argv[1]);
        
    if("compile"==temp) {
      std::cout << "Compiled Ok.\n";
      return 0;
    }
    else if(argc>2) {
      
      std::string thePath(argv[2]);
      std::ifstream theInput(thePath);
      if("count"==temp) {
        return ECE17::doWordsTest(theInput);
      }
      else if ("pairs"==temp) {
        return ECE17::doPairsTest(theInput);
      }
      else if ("compress"==temp) {
        std::string theContents;
        readFile(thePath, theContents);
        return ECE17::doCompressTest(theInput, theContents);
      }
    }
    std::cout << "No action taken.\n";
    return -1;
  }
  

  //student -- add your testing code...
  
  return 0;
}
