//
//  Mocks.hpp
//  RGAssignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Mocks_h
#define Mocks_h

#include "Card.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include "Game.hpp"

#include "Tester.hpp"
#include <iostream>

namespace ECE17 {
  
  //------ mock class for Card --------------------

  class CardTest : public Card {
  public:
    
    CardTest(Faces aFace=Faces::ace, Suits aSuit=Suits::clubs) : Card(aFace,aSuit) {
    }
    
    CardTest(const CardTest &aCopy) : Card(aCopy) {
    }
    
    CardTest& operator=(const CardTest &aCopy) {
      Card::operator=(aCopy); //let the parent do it...
      return *this;
    }
    
    ~CardTest() {}
    
    friend std::ostream& operator<<(std::ostream &anOutput, const CardTest &aCard) {
      switch(aCard.face) {
        case Faces::two : anOutput << "two "; break;
          //handle the other faces here...
        default: break;
      }
      switch(aCard.suit) {
        case Suits::hearts : anOutput << "hearts "; break;
          //handle the other suits here...
        default: break;
      }
      return anOutput;
    }

    static bool run(Tester &aTester) {
            
      //test ctor() --------------
      CardTest theCard1(Faces::two, Suits::hearts);
      CardTest theCard2(Faces::two, Suits::hearts);
      
      if(!aTester.isEqual(theCard1,theCard2)) {
        aTester.failed("Card::ctor()");
        return false;
      }
      
      //test copy ctor() --------------
      CardTest theCard3(theCard1);
      if(!aTester.isEqual(theCard1,theCard3)) {
        aTester.failed("Card::ctor(const Card &aCopy)");
        return false;
      }
        
      //test operator=() --------------
      CardTest theCard4(Faces::two, Suits::clubs);
      theCard1=theCard4;
      if(!aTester.isEqual(theCard1,theCard4)) {
        aTester.failed("Card::operator=(const Card &aCopy)");
        return false;
      }

      return true;
    }
    
  };

  //------ STUDENT: Add mock class for Hand --------------------

  //------ STUDENT: Add mock class for Deck --------------------

  //------ STUDENT: Add mock class for Player --------------------

  //------ STUDENT: Add mock class for Game --------------------


}

#endif /* Mocks_h */
