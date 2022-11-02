//
//  Deck.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Deck.hpp"
#include "Card.hpp"
using std::cout;

namespace ECE17 {
    Deck::Deck() {
        std::vector<Suits> VecSuits={Suits::diamonds,Suits::hearts,Suits::spades,Suits::clubs};
        for (auto aSuit : VecSuits) {
            for (int aFace = (int)Faces::two; aFace != ((int)Faces::ace +1); aFace++) {
                Card newCard = Card((Faces) aFace,aSuit);
                Deck::DequeCard52.push_back(newCard);
            }
        }
    }
    Deck::Deck(const Deck &aCopy) {
        *this=aCopy;
    }
    Deck::~Deck(){}
    Deck &Deck::operator=(const Deck& aCopy) {
        DequeCard52=aCopy.DequeCard52;
        return *this;
    }

    void Deck::shuffle() {
        Card temp;
        int randIndex = 0;
        int length=count();
        for (int i=0; i<length; i++) {
            randIndex = rand() % length;
            temp = DequeCard52[i];
            DequeCard52[i] = DequeCard52[randIndex];
            DequeCard52[randIndex] = temp;
        }
    }
    CardOpt Deck::take() {
        if(count()>1){
            Card dequeFront=DequeCard52.front();
            DequeCard52.pop_front();
            return dequeFront;
        }
        else{
            return std::nullopt;
        }
    }
    bool Deck::discard(ECE17::Card &aCard) {
        if (count()<52){
            DequeCard52.push_back(aCard);
            return true;
        }
        else{
            return false;
        }
    }

    size_t Deck::count() {
        return DequeCard52.size();
    }

    void Deck::show() {
        size_t length=count();

        for(size_t i=0;i<length;i++){
            cout<<"┌──┐"<<" ";
        }
        cout<<"\n";
        for(size_t i=0;i<length;i++){
            Card card= DequeCard52[i];
            cout<<"│";
            cout<<(int)card.face;
            if((char)card.suit=='S'){
                cout<<"♠";
            }
            else if((char)card.suit=='H'){
                cout<<"♥";
            }
            else if((char)card.suit=='D'){
                cout<<"♦";
            }
            else{
                cout<<"♣";
            }
            cout<<"│ ";
        }
        cout<<"\n";
        for(size_t i=0;i<length;i++){
            cout<<"└──┘"<<" ";
        }
        cout<<std::endl;
    }
    std::ostream& operator<<(std::ostream &anOutput, const Deck &aDeck) {
        for(Card card : aDeck.DequeCard52){
            anOutput<<card<<" ";
        }
        anOutput<<std::endl;
    return anOutput;
    }

}
