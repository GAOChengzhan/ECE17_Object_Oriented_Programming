//
//  Game.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Game.hpp"

namespace ECE17 {
    Game::Game() {
        player1=Player();
        player2=Player();
        deck=Deck();
    }
    Game::Game(const char *player1Name, const char *player2Name) {
        player1.setName(player1Name);
        player2.setName(player2Name);
        deck = Deck();
    };

    Game::Game(const ECE17::Game &aCopy) {
      *this=aCopy;
    }
    Game::~Game() {}
    Game &Game::operator=(const ECE17::Game &aCopy) {
        player1=aCopy.player1;
        player2=aCopy.player2;
        deck=aCopy.deck;
        return *this;
    }
  bool Game::willStartGame() {
    return true;
  }

}
