//
//  Player.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Hand.hpp"
using std::string;

namespace ECE17 {

  class Player {
  protected:
      string name;
      Hand aHand;
      int score;
  public:
      //OFC
      Player();
      Player(string name);
      Player(const Player &aCopy);
      Player &operator=(const Player &aCopy);
      ~Player();

      const char* getName();
      void setName(const char* aName);
      friend std::ostream& operator<<(std::ostream &anOutput,const Player &aPlayer);
  };

}

#endif /* Player_hpp */
