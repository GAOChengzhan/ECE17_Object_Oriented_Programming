//
//  Tester.hpp
//  RGAssignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Tester_h
#define Tester_h

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <typeinfo>
#include <string>
#include "Card.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"

const int kDeckSize{52};
const int kSuccess{0};
const int kConstructorError{100};
const int kCopyConstructorError{200};
const int kAssignmentError{300};
const int kContainsError{400};
const int kCountError{500};

namespace ECE17 {

  //this class only exists so we can test Card class...
  class MockCard : public Card {
  public:
    MockCard(Faces aFace=Faces::ace, Suits aSuit=Suits::clubs)
    : Card(aFace, aSuit) {}
    MockCard(const Card &aCopy) : Card(aCopy) {}
    
    bool matches(const MockCard &aCard) {
      return suit==aCard.suit && face==aCard.face;
    }
  };

  int testCards(std::ostream &anOutput) {
    MockCard theCard1; //default ctor, should be ace of clubs
    MockCard theCard2{Faces::ace, Suits::clubs}; //non-default ctor
    
    if(!theCard1.matches(theCard2))
      return kConstructorError;
      
    MockCard theCard3{theCard2}; //copy ctor...

    if(!theCard1.matches(theCard2))
      return kCopyConstructorError;

    MockCard theCard4{Faces::ace, Suits::hearts}; //ctor
    theCard3=theCard4;
    
    if(!theCard3.matches(theCard4))
      return kAssignmentError;

    return kSuccess;
  }

  //----------------------------------------------

  //this class only exists so we can test Hand class...
  class MockHand : public Hand {
  public:
    MockHand() : Hand() {}
    MockHand(const MockHand &aCopy) : Hand(aCopy) {}
    
    bool matches(const MockHand &aHand) {
      return true;
    }
  };

  int testHand(std::ostream &anOutput) {
    const size_t kHandSize{5};
    Deck theDeck;
    theDeck.shuffle();
    MockHand theHand1;
    for(size_t i=0;i<kHandSize;i++) {
      if(auto theCard=theDeck.take()) {
        theHand1.addCard(*theCard);
      }
      else return !kSuccess;
    }

    std::stringstream theOut1;
    theOut1 << theHand1;
    std::string theStr1=theOut1.str();

    Hand theHand2(theHand1);
    std::stringstream theOut2;
    theOut2 << theHand2;
    std::string theStr2=theOut2.str();

    if(theStr1!=theStr2) {
      anOutput << "hand copy-ctor error\n";
      return kCopyConstructorError;
    }
          
    Hand theHand3;
    theHand3=theHand1;
    std::stringstream theOut3;
    theOut3 << theHand3;
    std::string theStr3=theOut3.str();

    if(theStr1!=theStr3) {
      anOutput << "hand assignment error\n";
      return kCopyConstructorError;
    }

    if(kHandSize!=theHand1.count()) {
      anOutput << "hand count() error\n";
      return kCountError;
    }
//    std::cout<<theOut1.str();
    return kSuccess;
  }

  //----------------------------------------------

  int testPlayer(std::ostream &anOutput) {
    Player thePlayer1("John Smith");
    Player thePlayer2(thePlayer1);//question!!!
    
    std::stringstream theOut1;
    theOut1 << thePlayer1;
    std::string theStr1=theOut1.str();

    std::stringstream theOut2;
    theOut2 << thePlayer2;

    if(theStr1!=theOut2.str()) {
      std::cout << "player copy-ctor error\n";
      return kCopyConstructorError;
    }
    
    Player thePlayer3;
    thePlayer3=thePlayer1;

    std::stringstream theOut3;
    theOut3 << thePlayer3;
    if(theStr1!=theOut3.str()) {
      std::cout << "player assignment error\n";
      return kAssignmentError;
    }
    
    return kSuccess;
  }

  //----------------------------------------------

  //this class only exists so we can test Deck class...
  class MockDeck : public Deck {
  public:
    MockDeck() : Deck() {}
    MockDeck(const MockDeck &aCopy) : Deck(aCopy) {}
    
    bool matches(const MockHand &aDeck) {
      return true;
    }
  };


  int testDeck(std::ostream &anOutput) {
    
    Deck theDeck1;
    auto theCard=theDeck1.take();
            
    size_t theSize=theDeck1.count();
    if(1!=kDeckSize-theSize) {
      std::cout << kDeckSize<<" "<<theSize<<"deck initialization error\n";
      return kCountError;
    }
    
    Deck theDeck2(theDeck1);
    
    std::stringstream theOut1;
    theOut1 << theDeck1;
    std::string theStr1=theOut1.str();

    std::stringstream theOut2;
    theOut2 << theDeck2;
    std::string theStr2=theOut2.str();

    if((theStr1!=theStr2)|| (kDeckSize-theDeck2.count()!=1)) {
      std::cout << "deck copy-ctor error\n";
      return kCopyConstructorError;
    }
    
    Deck theDeck3;
    theDeck3=theDeck1;
    if(theDeck1.count()!=theDeck3.count()) {
      std::cout << "deck assignment error\n";
      return kAssignmentError;
    }

    return kSuccess;
  }

  //----------------------------------------------

  //this class only exists so we can test game class...
  class MockGame : public Game {
  public:
    MockGame() : Game() {}
    MockGame(const MockGame &aCopy) : Game(aCopy) {}
    
    bool matches(const MockGame &aGame) {
      return true;
    }
  };
  int testGame(std::ostream &anOutput) {
    return !kSuccess;
  }

  int compileTest(const ECE17::AboutMe &aStudent) {
    if(aStudent.getPID()!="Your PID") {
      if(aStudent.getName()!="Your name") {
        return kSuccess;
      }
    }
    return !kSuccess;
  }

}
#endif /* Tester_h */
