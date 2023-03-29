[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9905501&assignment_repo_type=AssignmentRepo)

# Blackjack
 > For files, CPP files are in the src folder, test files in the test folder, and header files in the header folder, while other files listed are correctly titled.
 >
 > Authors: [Anderson Wu (anderthenoob)](https://github.com/anderthenoob),
            [Casey Le (Axiion8)](https://github.com/Axiion8),
            [Justin An (anj501)](https://github.com/anj501),
            [Kyle Taing (KyleTaing)](https://github.com/KyleTaing),

## Project Description
 > When deciding on our project, we wanted to make a project that could be enjoyed over a long period of time as well as making a project that was easy to understand or already well known in terms of rules and how it's played. That's how we decided on making a blackjack project in order to fulfill those goals we had in mind. We're going to be using C++ for our project. This blackjack game includes a stack of cards without the 2 joker cards. You are given an amount of credits and if the your credits gets to 0 you are unable to play. The dealer is going to pass out 2 cards to itself (only revealing 1 card) and 2 cards to the player. After seeing the 2 cards, the player is going to have the options to hit (takes another card from the card stack), stand (take no more cards), double down (double the wager, take one more card and stand), split (this option is only avalable if the inital 2 cards given to you are the same value; split your 2 initial cards into 2 hands doubling your wager), and surrender (give up half of the bet and give up the hand). The project is expected to output the status of the blackjack game which includes, the player's hand, the dealer's hand, with the addition to different playstyle options mentioned before.
 > 
 > ## Phase II
 > In our project, everything will be reliant on the card class. The card class holds the value of each card, its respective suit, and the card's name. The deck class will store all our card objects in a vector which will be distributed to a player's hand. In the hand function, there will be functions that check if the hand's value will bust or count as a blackjack—while also has functions that manipulate the cards in the chosen hand, so drawing, viewing, and discarding the hand after the round is over. The player and dealer class will depend on the hand class, as most of their functions will be used to manipulate the hand. This means hitting, standing, doubledown, all uses the hand class. The player class will additionally have the option to see their name, how much money they currently have, how much they want to bet, and the additional options to double down or surrender during the round.

 > Card Class:
 > * void setValue(int) sets cardValue
 > * void setName(string) sets name
 > * void setSuit(string) sets suit
 > * int getValue() returns the cardValue
 > * string getName() returns the name
 > * string getSuit() returns the suit
 > * bool getAce() returns true cardAce
 > 
 > Deck Class:
 > * void generateDeck() generates a vector with 52 Card object
 > * void shuffleDeck() mixes up order the of the vector
 > * card* drawCard() returns a removed card from vector
 > * void returnCard(card*) returns a card back to the vector
 > * bool isEmpty() const return false if empty
 > * int getDeckSize() returns the size of the vector
 > 
 > Hand Class:
 > * bool checkBustHand() returns true if handValue is larger than 21
 > * bool checkJackHand() returns true if hadnValue is equals to 21 
 > * int getValueHand() returns handValue
 > * void drawCardHand(card*) prints out what card the user draws
 > * void viewHand() let player see his cards
 > * void clearHand(card*) clears the Hand<>
 > * bool isEmpty() returns false if empty
 > * bool isAceHand() returns aceHand
 > * int getHandSize() returns the size of the vector
 > 
 > Dealer Class:
 > * void dealerDraw() calls drawCardHand()
 > * void dealerViewHand() couts Dealer's cards
 > * hand* getDealerHand() returns dealerHand
 > 
 > Player Class:
 > * string getName() returns name
 > * int viewMoney() returns money
 > * void wonBet() adds player's placed and won bets back to money
 > * void placeBet(int) deducts the amount of bet placed from money
 > * void doubleDownBet(int) deducts twice the amount of bet placed from money
 > * int viewBet() return bet
 > * void hit(deck*) calls drawCardHand()
 > * void stand() ends round, dealer's turn
 > * void doubleDown(deck*) double the bet, hit once and stand
 > * void drawBet() adds the player's placed bet back to money
 > * hand* getCurrentHand() returns currentHand
 > * void output() couts Player's deck of cards and amount of bet placed

## Class Diagram
 > ![uml](https://user-images.githubusercontent.com/110501128/222856648-8de8d71b-d211-432f-b11d-1517cb55bf24.png)

 
 > ## Phase III
 > After looking at our class diagram, we applied SOLID principles to make the project more concise and manageable. We applied Single Responsibility Principle (SRP) and Open-Closed Principle (OCP) to our class diagram. We first used SRP for the Card class to represent the playing card. The change was for the card class to be separate from the deck class where the Card class would be able to set and get the suit and value of the card. This allows the Card class to be independent of the Deck class where it's more flexible and functional. The SRP helped us make our code more organized and have a single purpose for the Card class. Next we applied another SRP, to our Deck Class which represents the deck of cards. We applied this principle by having the Deck Class only have functionality for deck of cards and doesn’t do anything else. This change of adding the Deck Class helped with only having one purpose to the class and not having it so disorganized. We can also add on to the deck class without having to change anything in the Card Class. Finally, we applied the OCP where we have the Deck class and don’t need to modify the Card class if we wanted to add features to the Deck class. Since incorporating the Deck Class we don’t have to change the existing functions and are able to add more functions without changing the existing code. The OCP helps with managing new functions and we don’t have to worry about changing existing code in order to implement new functions to the class. 
 
 > ## New Class Diagram
 > ![newuml](https://user-images.githubusercontent.com/110501128/222856040-854324e9-bd44-4da4-a816-7ca9daf0b8fa.png)

 
 > ## Final deliverable
 > ## Updated Class Diagram
 > ![4uml](https://user-images.githubusercontent.com/110501128/226063138-d7ab2045-1d80-4506-944d-2ca687c8b022.png)
 
 ## Screenshots
 > ![ss 1](https://user-images.githubusercontent.com/84153224/226052553-c0f2761b-b74a-46fd-a614-068f399dc84e.jpg)
 > ![ss 2](https://user-images.githubusercontent.com/84153224/226052598-9105f624-4cc3-45a2-92f2-b28dfbe3cfbc.jpg)
 > ![ss 3](https://user-images.githubusercontent.com/84153224/226052612-59d78b63-6561-4612-b849-5c6767fcd49e.jpg)
 ## Installation/Usage
 > In order to install the BlackJack game you would need first `git clone` the respository to get all the files. After git clone, run `git pull origin master` in order to have the files in your local computer. Then run `cmake .` and `make` in order to get the CMakeFiles. Finally, to start the game run the executable `./bin/game` to start playing BlackJack.
 > - First, the program will ask your name and user will reply with their name
 > - Then, there will be menu options of 1.View profile, 2.Win ratio, 3.Start game, and 4.Quit game and choose the number of your choice.
 > - If 2 was chosen (which is recommended for the first try), the program will then ask you how much you would like to bet. The user should reply with how much money 
 >   they want to bet, then type confirm to continue.
 > - Then the program will output the dealer's hand and your hand. Then you will have the options of your next move whether it is the 1.Hit 2. Stand 3. Double Down and
 >   and choose one of these numbers
 >   
 >   *Note: Hit is to get a card, Stand is to hold your total and end your current turn, Double Down is to double the bet after receiving one card(hit) and then 
 >   Stand*
 > - You will continue to choose one of these choices until the dealer has won, user has won, or there is a draw, then program will move user to menu.
 > - When you are at the menu, you may also choose 1 to view your profile name and money, choose 2 to see your win ratio, or choose 3 to start a new game.
 > - When user wants to quit the game, user will choose 4 to quit the game.
 ## Testing
 > Our project was tested and validated with the googletest framework. In our test files, we would use the smoke testing methodology to ensure each of our functions were working as expected. Once we guaranteed there were no bugs in our class functions, we proceeded to Valgrind our final project to check for any potential memory leaks.
 
