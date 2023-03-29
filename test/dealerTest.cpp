#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/dealer.hpp"

TEST(dealerTest, dealerConstructorTest){
    EXPECT_NO_THROW(dealer d);
}
TEST(dealerTest, dealerDrawTest){
    deck* testDeck = new deck();
    dealer* testDealer = new dealer();
    testDealer->dealerDraw(testDeck);
    EXPECT_EQ(testDealer->getDealerHand()->getHandSize(), 1);
    delete testDeck;
    delete testDealer;
    testDeck = nullptr;
    testDealer = nullptr;
}

