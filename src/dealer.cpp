#include "../header/dealer.hpp"

dealer::dealer() {
    this->dealerHand = new hand();
}

dealer::~dealer() {
    delete dealerHand;
    this->dealerHand = nullptr;
}

void dealer::dealerDraw(deck* iCard) {
    card* newCard = iCard->drawCard();
    dealerHand->drawCardHand(newCard);
}

void dealer::dealerViewHand() {
    cout << "Dealer cards: ";
    cout << endl << "Dealer ";
    dealerHand->viewHand();
    cout << "Dealer total value is: " << dealerHand->getValueHand() << endl;
}

hand* dealer::getDealerHand(){
    return this->dealerHand;
}

