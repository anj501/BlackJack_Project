#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/hand.hpp"

TEST(handTest, ConstructorTest){
    EXPECT_NO_THROW(hand h);
}
 
TEST(handTest, DestructorTest){
    hand* h = new hand();
    delete h;
    h = nullptr;
    EXPECT_EQ(h,nullptr);
}

TEST(handTest, checkBustHandTest){
    hand* h = new hand();
    h->drawCardHand(new card(11, "Ace", "Diamonds", true ));
    h->drawCardHand(new card(10, "Ten", "Spades", false ));
    h->drawCardHand(new card(10, "Queen", "Spades", false ));
    EXPECT_TRUE(h->checkBustHand());
    delete h;
    h = nullptr;
}

TEST(handTest, checkJackHandTest){
    hand* h = new hand();
    h->drawCardHand(new card(11, "Ace", "Diamonds", true ));
    h->drawCardHand(new card(10, "Ten", "Spades", false ));
    EXPECT_TRUE(h->checkJackHand());
    delete h;
    h = nullptr;
}

TEST(handTest, getValueHandTest){
    hand* h = new hand();
    h->drawCardHand(new card(2, "Two", "Diamonds", false ));
    h->drawCardHand(new card(5, "Five", "Clubs", false ));
    EXPECT_EQ(h->getValueHand(), 7);
    delete h;
    h = nullptr;
}

TEST(handTest, getValueHandTest2){
    hand* h = new hand();
    h->drawCardHand(new card(11, "Ace", "Diamonds", true ));
    h->drawCardHand(new card(9, "Nine", "Spades", false ));
    h->drawCardHand(new card(10, "Ten", "Hearts", false ));
    EXPECT_EQ(h->getValueHand(), 30);
    delete h;
    h = nullptr;
}

TEST(handTest, isAceHandTest){
    hand* h = new hand();
    card* c = new card(2, "Two", "Diamonds", false);
    h->drawCardHand(c);
    EXPECT_EQ(h->isAceHand(), false);
}

TEST(handTest, isAceHandTest2){
    hand* h = new hand();
    card* c = new card(1, "Ace", "Clubs", true);
    h->drawCardHand(c);
    EXPECT_EQ(h->isAceHand(), true);
    delete c;
    c = nullptr;
}

TEST(handTest, clearHandTest){
    hand* h = new hand();
    card* c = new card(1, "Ace", "Clubs", true);
    h->drawCardHand(c);
    EXPECT_EQ(h->isAceHand(), true);
}

TEST(HandTest, ClearHandTest) {
    deck* d = new deck();
    d->shuffleDeck();
    hand* h = new hand();
    h->drawCardHand(d->drawCard());
    h->drawCardHand(d->drawCard());
    h->clearHand(d);
    EXPECT_TRUE(h->isEmpty());
    delete h;
    h = nullptr;
    delete d;
    d = nullptr;
}