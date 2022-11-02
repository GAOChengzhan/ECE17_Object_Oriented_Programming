//
//  MadlibUserWordProvider.cpp
//  Assignment2
//

#include "MadlibUserWordProvider.hpp"
#include <iostream>

MadlibUserWordProvider::MadlibUserWordProvider() : MadlibWordProvider() {
}
MadlibUserWordProvider::MadlibUserWordProvider(const MadlibUserWordProvider &aMadlibUserWordProvider) {
    *this=aMadlibUserWordProvider;
}
MadlibUserWordProvider &MadlibUserWordProvider::operator=(const MadlibUserWordProvider &aMadlibUserWordProvider) {
    return *this;
}
MadlibUserWordProvider::~MadlibUserWordProvider(){}

std::string MadlibUserWordProvider::getSubstituteWord(WordType aType) {//why not override here
  //STUDENT: ask the user for console input (std::cin), and return their input...
  std::cout<<"Please enter a/an "<<getLabelForType(aType)<<":";
  std::string UserInput;
  std::cin>>UserInput;
  if (UserInput!=""){
      return UserInput;
  }
  else{
      std::cerr<<"Please do enter the word!"<<std::endl;
      return "Error";
  }
}
