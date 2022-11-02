//
//  Deck.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>
#include <deque>
#include "Hand.hpp"
#include "Card.hpp"

namespace ECE17 {

  class Deck {
  protected:
      //add data members
      std::deque<Card> DequeCard52;
  public:
    
    //STUDENT: implement this class as outlined in the readme...
    //OCF
    Deck();
    Deck(const Deck &aCopy);
    ~Deck();
    Deck& operator=(const Deck& aCopy);
    void shuffle();
    CardOpt take();
    bool discard(Card &aCard);
    size_t count();
    void show();
    //this method will print the deck to the terminal
    friend std::ostream& operator<<(std::ostream &anOutput,const Deck &aDeck);
    //I need to hold 52 cards, but an ARRAY
    //would be a poor choice...

  };

}

#endif /* Deck_hpp */
