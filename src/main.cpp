#include "../header/card.hpp"
#include "../header/deck.hpp"
#include "../header/hand.hpp"
#include "../header/dealer.hpp"
#include "../header/player.hpp"

#include <iomanip> //to transform win ratio into percentage
#include <unistd.h> //for sleep() function (linux based server)

using namespace std;

void optionDisplay();
void optionGameDisplay();
double percentage(double, double);

int main(){

    deck* gameDeck = new deck(); //generate deck object
    gameDeck->shuffleDeck();

    string playerNameInput = ""; //set up player object
    cout << "What is your name?" << endl; 
    cin >> playerNameInput;
    player* user = new player(playerNameInput);

    double gameCnt = 0; //records game win ratio
    double gameWin = 0;

    int menuOptionInput = 0;
    optionDisplay(); //display menu
    cin >> menuOptionInput;

    dealer* host = new dealer(); //set up dealer object

    while(menuOptionInput != 4){//while loop until player presses 4 to quit program
        
        if(menuOptionInput == 1){//View Profile // done
            cout << "Name: " << playerNameInput << endl;
            cout << "Current Money: " << user->viewMoney() << endl << endl;
        }
        if(menuOptionInput == 2){//Win Ratio // done
            if(gameCnt == 0){ //incase player hasn't played a game yet
                cout << "You have no past game history" << endl << endl;
            }
            else{ //outputs percentage and games won/total games
                cout << fixed << setprecision(2) << "Win ratio: " << percentage(gameWin,gameCnt) << "% (" 
                 << gameWin << '/' << gameCnt << ")" << endl << endl;
            }
        }

        if(menuOptionInput == 3){//StartGame // WIP
            ++gameCnt;//tracks how many games player has done
            
            bool userStandStatus = false;
            string playerBetConfirm = "";

            while(playerBetConfirm != "confirm"){//decides/confirms how much player wants to bet
                int betInput = 0;
                cout << "How much would you like to bet? ";
                cin >> betInput;
                cout << endl << "You're betting $" << betInput << "; type confirm to continue." << endl;
                cin >> playerBetConfirm;
                cout << endl << endl;
                user->placeBet(betInput);
            }
            

            host->dealerDraw(gameDeck); //dealer draws 1 card
            host->dealerViewHand(); //displays dealer's card
            cout << endl;

            user->hit(gameDeck); //player draws 2 cards
            user->hit(gameDeck);
            user->output(); //displays cards in hand

            while(!user->getCurrentHand()->checkBustHand() && !userStandStatus){// WIP // while loop only runs when hand isn't bust and player doesn't stand
                optionGameDisplay();
                int gameMenuInput = 0;
                cin >> gameMenuInput;

                if(gameMenuInput == 1){ //hit
                    user->hit(gameDeck);
                }
                else if(gameMenuInput == 2){ //stand
                    userStandStatus = true;
                }
                else if(gameMenuInput == 3){ //double down
                    int tempBet;
                    user->hit(gameDeck);
                    
                    tempBet = user->viewBet();//doubling bet
                    user->drawBet();
                    user->placeBet(2*tempBet);

                    userStandStatus = true;
                }
                else{
                    cout << "Invalid input, please try again." << endl << endl;
                }
                host->dealerViewHand();
                user->output();
                cout << endl;
            }

            if(user->getCurrentHand()->checkBustHand()){ //if player bust, set bet to 0 // done
                    user->getCurrentHand()->clearHand(gameDeck); //returns cards back to deck
                    cout << "Player hand bust! Dealer won!" << endl << endl;
                }

            else{ //else, while loop so dealer tries to beat player
                while(host->getDealerHand()->getValueHand() < 17){//stops once dealer's hand is greater or equal 17
                    host->dealerDraw(gameDeck); //keep drawing till while loop stops
                    host->dealerViewHand();
                }

                if(host->getDealerHand()->checkBustHand()){ //if dealer bust, then give player their winnings & ++gameWin
                    user->wonBet();
                    ++gameWin;
                    host->getDealerHand()->clearHand(gameDeck); //return cards to deck
                    user->getCurrentHand()->clearHand(gameDeck);
                    cout << "Dealer hand bust! Player won!" << endl << endl;
                }
                else if(host->getDealerHand()->getValueHand() == user->getCurrentHand()->getValueHand()){ //if dealer draws
                    user->drawBet();
                    --gameCnt;
                    host->getDealerHand()->clearHand(gameDeck); //return cards to deck
                    user->getCurrentHand()->clearHand(gameDeck);
                    cout << "Both hands drew! No one won!" << endl << endl;
                }
                else if(host->getDealerHand()->getValueHand() < user->getCurrentHand()->getValueHand()){ //dealer lost
                    user->wonBet();
                    ++gameWin;
                    host->getDealerHand()->clearHand(gameDeck); //return cards to deck
                    user->getCurrentHand()->clearHand(gameDeck);
                    cout << "Dealer lost! Player won!" << endl << endl;
                }
                else if(host->getDealerHand()->getValueHand() > user->getCurrentHand()->getValueHand()){ // dealer won
                    host->getDealerHand()->clearHand(gameDeck); //return cards to deck
                    user->getCurrentHand()->clearHand(gameDeck);
                    cout << "Player lost! Dealer won!" << endl << endl;
                }
            }
        }
        
        optionDisplay();//reopens menu for while loop decision
        cin >> menuOptionInput;
    }
    delete user;
    delete host;
    delete gameDeck;
}



void optionDisplay(){
    cout << "Menu Options:" << endl
         << "1. View profile" << endl
         << "2. Win ratio" << endl
         << "3. Start game" << endl
         << "4. Quit game" << endl << endl
         << "What would you like to do? ";
}

void optionGameDisplay(){
    cout << "What's your next move?" << endl
         << "1. Hit" << endl
         << "2. Stand" << endl
         << "3. Double Down" << endl << endl
         << "What would you like to do? ";
}

double percentage(double dividend, double divisor) {
  double result = (dividend / divisor) * 100;
  return result;
}