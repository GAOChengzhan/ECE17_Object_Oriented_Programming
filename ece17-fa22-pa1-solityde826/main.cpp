//
//  main.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "AboutMe.hpp"
#include "Tester.hpp"
#include "Game.hpp"
#include "Card.hpp"


int main(int argc, const char * argv[]) {
      
  srand(static_cast<uint32_t>(time(0))); //randomize...

  if(argc>1) {
      
    std::string temp(argv[1]);
    std::stringstream theStream;
    
    //This is a poor way to write this logic. Can you see why?

    int theResult=0;
    if("compile"==temp) {
      ECE17::AboutMe theStudent;
      theResult=compileTest(theStudent);
    }
    else if("cards"==temp) {
      theResult=ECE17::testCards(theStream);
    }
    else if ("hand"==temp) {
      theResult=ECE17::testHand(theStream);
    }
    else if ("deck"==temp) {
      theResult=ECE17::testDeck(theStream);
    }
    else if ("player"==temp) {
      theResult=ECE17::testPlayer(theStream);
    }
    else if ("game"==temp) {
      theResult=ECE17::testGame(theStream);
    }
    else {
      temp="unknown";
      theResult=1;
    }
  
    static const char* theStatus[]={"PASS","FAIL"};
    std::cout << temp << " test " << theStatus[theResult]<<"\n";
    std::cout << theStream.str() << "\n"; //output whatever user provided
    return theResult;
  }
  
  else {
    ECE17::Game theGame;
    theGame.willStartGame();
  }
      
  return 0;
}
