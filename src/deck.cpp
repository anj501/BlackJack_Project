#include "../header/deck.hpp"

deck::deck(){
    for(unsigned int i = 0; i < 6; ++i){//generates 6 decks
        generateDeck();
    }
}

void deck::generateDeck(){
    for(unsigned int i = 0; i < 4; ++i){ //i == 4 to generate each cardSuit once
        
        string cardSuit = "";//if statements to see what suit will be generated next

        if(i == 0){
            cardSuit = "Clubs";
        }
        else if(i == 1){
            cardSuit = "Diamonds";
        }
        else if(i == 2){
            cardSuit = "Hearts";
        }
        else if(i == 3){
            cardSuit = "Spades";
        }
        else{ //incase i iteration somehow goes over 4
            cout << "cardSuit iteration error, variable i > 4";
        }

        for(unsigned int j = 1; j < 14; ++j){//nested for loop to generate every card per suit
            
            string cardName = "";//if statements to see what card will be generated next

            if(j == 1){
                cardName = "Ace";
            }
            else if(j == 2){
                cardName = "Two";
            }
            else if(j == 3){
                cardName = "Three";
            }
            else if(j == 4){
                cardName = "Four";
            }
            else if(j == 5){
                cardName = "Five";
            }
            else if(j == 6){
                cardName = "Six";
            }
            else if(j == 7){
                cardName = "Seven";
            }
            else if(j == 8){
                cardName = "Eight";
            }
            else if(j == 9){
                cardName = "Nine";
            }
            else if(j == 10){
                cardName = "Ten";
            }
            else if(j == 11){
                cardName = "Jack";
            }
            else if(j == 12){
                cardName = "Queen";
            }
            else if(j == 13){
                cardName = "King";
            }
            else{
                cout << "cardName iteration error, variable j > 14";
            }

            if(j == 1){
                deckV.push_back(new card(11, cardName, cardSuit, true));
            }
            else if(1 < j && j <=10){
                deckV.push_back(new card(j, cardName, cardSuit, false));
            }
            else if(10 < j && j <= 13){
                deckV.push_back(new card(10, cardName, cardSuit, false));
            }
        }
    } 
}

void deck::shuffleDeck(){
    random_shuffle(this->deckV.begin(), this->deckV.end());
}

deck::~deck(){// Delete each card object in the deck vector
    for (auto& cardPtr : deckV) {
        delete cardPtr;
        cardPtr = nullptr;
    }
}

card* deck::drawCard(){
    if (isEmpty()) {// handle empty deck
        return nullptr;
    }
    card* temp;
    temp = deckV.back();
    deckV.pop_back();
    return temp;
}

void deck::returnCard(card* input){
    deckV.push_back(input);
}

bool deck::isEmpty() const{
    return deckV.empty();
}

int deck::getDeckSize(){
    return deckV.size(); 
}

