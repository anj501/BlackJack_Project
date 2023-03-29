#ifndef DECK_HPP
#define DECK_HPP

#include "card.hpp" //for deck()
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for shuffleDeck()

class deck{
    private:
        vector<card*> deckV;    
    public:
        deck(); //generate the deck
        ~deck();
        void generateDeck();//deck() helper function
        void shuffleDeck();
        card* drawCard();
        void returnCard(card*);
        bool isEmpty()const;
        int getDeckSize();
};

#endif