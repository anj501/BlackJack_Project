#ifndef DEALER_HPP
#define DEALER_HPP

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class dealer {
    private:
    hand* dealerHand;

    public:
    dealer();
    ~dealer();

    void dealerDraw(deck* iCard);
    void dealerViewHand();
    hand* getDealerHand();

};

#endif