//
//  Game.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Player.hpp"
#include "Hand.hpp"
#include "Deck.hpp"

//STUDENT -- you need to finish this class!

namespace ECE17 {

  class Game {
  public:
      Game();
      Game(const char *player1_name, const char *player2_name);
      Game(const Game &aCopy);
      ~Game();
      Game& operator=(const Game& aCopy);
    //Student -- add methods here (including OCF)...
    
    bool willStartGame();
    
  protected:
    Deck deck;
    Player player1;
    Player player2;
    //Student -- add data members here...

  };

}


#endif /* Game_hpp */
