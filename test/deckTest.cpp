#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/deck.hpp"

TEST(deckTest, deckConstrutorTest){
    EXPECT_NO_THROW(deck d);
}

TEST(deckTest, generateDeckTest){
    deck* d = new deck();
    ASSERT_EQ(d->getDeckSize(), 6*4*13);
    delete d;
    d = nullptr;
}

TEST(deckTest, shuffleDeck){
    deck* d = new deck();
    EXPECT_NO_THROW(d->shuffleDeck());
    delete d;
    d = nullptr;
}

TEST(deckTest, shuffleDeckTest){
    deck* d1 = new deck();
    d1->shuffleDeck();
    deck* d2 = new deck();
    d2->shuffleDeck();
    EXPECT_NE(d1->drawCard(), d2->drawCard());
    delete d1;
    delete d2;
    d1 = nullptr;
    d2 = nullptr;
}

TEST(deckTest, destructorTest) {
    deck* d = new deck();
    delete d;
    d = nullptr;
    EXPECT_EQ(d,nullptr);
}

TEST(deckTest, ReturnCardTest) {
    deck* d = new deck();
    card* c = new card(1, "Ace", "Clubs", true);
    d->returnCard(c);
    EXPECT_EQ(d->getDeckSize(), 313);
}

TEST(deckTest, isEmpty) {
    deck* testDeck = new deck();
    EXPECT_FALSE(testDeck->isEmpty()); 
    while (!testDeck->isEmpty()) {
        testDeck->drawCard();
    }
    EXPECT_TRUE(testDeck->isEmpty()); 
    delete testDeck;
    testDeck = nullptr;
}

TEST(deckTest, drawsCard) {
    deck* testDeck = new deck();
    card* testCard = testDeck->drawCard();
    EXPECT_NE(testCard, nullptr); 
    EXPECT_EQ(testDeck->getDeckSize(), 6 * 52 - 1);
    delete testCard;
    delete testDeck;
    testCard = nullptr;
    testDeck = nullptr;
}