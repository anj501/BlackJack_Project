#include "../header/hand.hpp"

hand::hand(){
    this->handValue = 0;
    this->aceHand = false;
    this->numAces = 0;
    //this->bet = 0;
}

hand::~hand(){
    for (auto& cardPtr : handV){
        delete cardPtr;
        cardPtr = nullptr;
    }
}

bool hand::checkBustHand() {
    int handValue = 0;

    handValue = this->getValueHand();

    return (handValue > 21);
}

bool hand::checkJackHand() {
    return (this->getValueHand() == 21);
}

/*void hand::setBet(int input){
    this->bet = input;
}

int hand::wonBet(){
    return 2*bet;
}*/

int hand::getValueHand() {
    int value = 0;
    int numAces = 0;

    for (unsigned int i = 0; i < handV.size(); i++) {
        int temp = handV.at(i)->getValue();
        if (temp == 11) {
            numAces++;
        }
        value += temp;
    }

    while (value <= 11 && numAces > 0) {
        value += 10;
        numAces--;
    }

    return value;
}

void hand::drawCardHand(card* inputCard){
    handV.push_back(inputCard);
    if(inputCard->getAce()){
        this->aceHand = true;
        this->numAces++;
    }
}

void hand::viewHand(){
    cout << "hand:" << endl;
    for(unsigned int i = 0; i < handV.size(); ++i){
        cout << handV.at(i)->getSuit() << ' ' 
        << handV.at(i)->getName() 
        << " (" << handV.at(i)->getValue() 
        << ')' << endl;
    }
}

void hand::clearHand(deck* returnDeck){//WIP
    while (!isEmpty()) {// handle empty deck
        card* temp;
        temp = handV.back();
        returnDeck->returnCard(temp);
        handV.pop_back();
    }
}

bool hand::isEmpty(){
    return handV.empty();
}

bool hand::isAceHand(){
    return aceHand;
}

int hand::getHandSize(){
    return handV.size();
}