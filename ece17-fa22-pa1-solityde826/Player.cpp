//
//  Player.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Player.hpp"

namespace ECE17 {
    Player::Player() {
        name="Null";
    }
    Player::Player(string aName) {
        name=aName;
    }
    Player::Player(const Player &aCopy) {
        *this=aCopy;
    }
    Player::~Player() {}
    Player &Player::operator=(const Player &aCopy){
        name=aCopy.name;
        return *this;
    };
    const char *Player::getName() {
        char* res= &name[0];
        return res;
    }

    void Player::setName(const char *aName) {
        name=aName;
    }
    std::ostream& operator<<(std::ostream &anOutput, const Player &aPlayer){
        return anOutput;
    }
}
