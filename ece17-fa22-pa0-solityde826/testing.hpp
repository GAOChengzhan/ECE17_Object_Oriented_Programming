//
//  testing.hpp
//  PA0
//
//  Created by rick gessner on 3/26/22.
//  Modified by vikash gilja on 9/21/22.
//

#ifndef testing_h
#define testing_h

#include <iostream>
#include <sstream>
#include <map>
#include "AboutMe.hpp"

static const char* theStatus[]={"FAIL","PASS"};

bool isValidStudent(const ECE17::AboutMe &aStudent) {
  if(aStudent.getPID()!="Your PID") {
    if(aStudent.getName()!="Your name") {
      return true;
    }
  }
  return false;
}

bool compileTest(const ECE17::AboutMe &aStudent) {
  bool theResult{isValidStudent(aStudent)};
  std::cout << "Compile test " << theStatus[theResult] << "\n";
  std::cout << "Author: " << aStudent.getName() << "\n";
  return true;
}

bool validateOutput(const std::string &anOutput) {
  std::stringstream theInput(anOutput);
  std::string theWord;
  size_t      theValue{0},theCount{0};
  
  const char* kTests[]={"for","while","do"};
  std::map<std::string,size_t> theCounts;
  
  for(auto theKeyword: kTests) {
    theInput >> theWord >> theCount;
    if(theWord!=theKeyword) return false;
    theCounts[theKeyword]=theCount;
    for(size_t i=0;i<theCount;i++) {
      theInput >> theWord >> theValue;
      if(theWord!=theKeyword) return false;
      theCounts[theKeyword]--;
    }
  }
  return !(theCounts["for"]+theCounts["while"]+theCounts["do"]);
}

bool basicTest(const std::string &anOutput) {
  ECE17::AboutMe theStudent;
  
  bool theResult{isValidStudent(theStudent)
                  && validateOutput(anOutput)};
  
  //STUDENT: Initialize this with your personal data...
  std::cout << "Basic test " << theStatus[theResult] << "\n";
  std::cout << "Author: " << theStudent.getName() << "\n";
  return true;
}

#endif /* testing_h */
