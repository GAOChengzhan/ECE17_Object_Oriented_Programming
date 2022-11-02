//
//  Hand.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Hand.hpp"
#include <vector>

namespace ECE17 {
    Hand::Hand() {
        std::vector<Card> VecCard;
    }
    Hand::Hand(const Hand &aCopy) {
        *this=aCopy;
    }
    Hand::~Hand() {}
    Hand& Hand::operator=(const Hand &aCopy) {
        VecCard=aCopy.VecCard;
        return *this;
    }

    bool Hand::addCard(const ECE17::Card &aCard){
        if (count()<kCardsPerHand){
            VecCard.push_back(aCard);
            return true;
        }
        else{
        return false;
        }
    }

    CardOpt Hand::discard(ECE17::Faces aFace, ECE17::Suits aSuit) {
        int length=count();
        if (length>0){
            for(int i=0;i<length;i++) {
//                Card aDiscard=Card(aFace,aSuit);
                if (VecCard[i].face==aFace && VecCard[i].suit==aSuit){
                    return  VecCard[i];
                }
            }
            return std::nullopt;
        }
        else{
            return std::nullopt;
        }
    }

    size_t Hand::count() {
        return VecCard.size();
    }
    bool Hand::contains(const Card &aCard) {
        for(int i=0;i<count();i++)
        {
            if(aCard==VecCard[i]){
                return true;
            }
        }
        return false;
    }
    std::ostream& operator<<(std::ostream &anOutput,const Hand &aHand) {
    //STUDENT: implement this to show the hand on the output console...
        for (Card card : aHand.VecCard) {
            anOutput<<card<<" ";
        }
        anOutput<<std::endl;
        return anOutput;
    }
}
