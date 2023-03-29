#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/card.hpp"

TEST(cardTest1, testConstructor1){
    card *cardPTR = new card();
    EXPECT_EQ(cardPTR->getValue(), 0);
    EXPECT_EQ(cardPTR->getName(),"default");
    EXPECT_EQ(cardPTR->getName(),"default");
    EXPECT_EQ(cardPTR->getAce(), false);
    delete cardPTR;
    cardPTR = nullptr;
}

TEST(cardTest2, testConstructor2){
    card *cardPTR = new card(2, "Two", "Spades", false);
    EXPECT_EQ(cardPTR->getValue(), 2);
    EXPECT_EQ(cardPTR->getName(),"Two");
    EXPECT_EQ(cardPTR->getSuit(),"Spades");
    EXPECT_EQ(cardPTR->getAce(), false);
    delete cardPTR;
    cardPTR = nullptr;
}

TEST(cardTest3, test_setValue_and_getValue){
    card *cardPTR = new card();
    cardPTR->setValue(123);
    EXPECT_EQ(cardPTR->getValue(), 123);
    delete cardPTR;
    cardPTR = nullptr;
}

TEST(cardTest4, test_setName_and_getName){
    card *cardPTR = new card();
    cardPTR->setName("Ace");
    EXPECT_EQ(cardPTR->getName(), "Ace");
    delete cardPTR;
    cardPTR = nullptr;
}

TEST(cardTest5, test_setSuit_and_getSuit){
    card *cardPTR = new card();
    cardPTR->setSuit("Spades");
    EXPECT_EQ(cardPTR->getSuit(), "Spades");
    delete cardPTR;
    cardPTR = nullptr;
}