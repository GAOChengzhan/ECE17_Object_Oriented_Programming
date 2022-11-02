//
//  Hand.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <optional>
#include "Card.hpp"

namespace ECE17 {

  const int kCardsPerHand{5};

  using CardOpt = std::optional<Card>;

  class Hand {
  protected:
      //add data members
      std::vector<Card> VecCard;

  public:
      //STUDENT: implement this class from assigment...
      //OCF
      Hand();
      Hand(const Hand &aCopy);
      ~Hand();
      Hand &operator=(const Hand &aCopy);

      //this will show a hand on the console...
      friend std::ostream &operator<<(std::ostream &anOutput,
                                      const Hand &aHand);

      //how will you "hold" the cards you're given?
      bool addCard(const Card &aCard);

      CardOpt discard(Faces aFace, Suits aSuit);

      size_t count();

      bool contains(const Card &aCard);
      friend std::ostream& operator<<(std::ostream &anOutput,const Hand &aHand);
  };
}
#endif /* Hand_hpp */