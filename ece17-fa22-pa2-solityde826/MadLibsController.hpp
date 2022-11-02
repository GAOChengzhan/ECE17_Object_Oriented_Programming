//
//  MadLibsController.hpp
//  Assignment2
//


#ifndef MadLibsController_hpp
#define MadLibsController_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "MadlibWordProvider.hpp"

class MadLibsController {
public:

    MadLibsController(); //default ctor
    bool  runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput);
    bool  readFile(const char *aFilename);
    void  getSubstitutes(MadlibWordProvider &aProvider);
    void  showFinishedStory(std::ostream &anOutput);
    std::vector<std::string> getWords();
  
protected:
    std::vector<std::string> words; //collected from users...
    std::vector<std::string> raw_file;
    std::vector<std::string> substituteWords;
    std::vector<std::size_t> subPosition;
    // You'll probably want to add some additional data members!!
};

#endif /* MadLibsController_hpp */
