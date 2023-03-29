cmake_minimum_required(VERSION 3.2)
project(Blackjack)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

add_subdirectory(test/googletest)

#executables
add_executable(cardTest
    header/card.hpp
    src/card.cpp
    test/cardTest.cpp
)

add_executable(deckTest
    header/deck.hpp
    header/card.hpp
    src/card.cpp
    src/deck.cpp
    test/deckTest.cpp
)

add_executable(handTest
    header/deck.hpp
    header/card.hpp
    header/hand.hpp
    src/card.cpp
    src/deck.cpp
    src/hand.cpp
    test/handTest.cpp
)
add_executable(dealerTest
    header/deck.hpp
    header/card.hpp
    header/hand.hpp
    header/dealer.hpp
    src/card.cpp
    src/deck.cpp
    src/hand.cpp
    src/dealer.cpp
    test/dealerTest.cpp
)
add_executable(playerTest
    header/deck.hpp
    header/card.hpp
    header/hand.hpp
    header/player.hpp
    src/card.cpp
    src/deck.cpp
    src/hand.cpp
    src/player.cpp
    test/playerTest.cpp
)
add_executable(game
    header/deck.hpp
    header/card.hpp
    header/hand.hpp
    header/dealer.hpp
    header/player.hpp
    src/card.cpp
    src/deck.cpp
    src/hand.cpp
    src/dealer.cpp
    src/player.cpp
    src/main.cpp
)

add_executable(valgrindTestFiles
    header/deck.hpp
    header/card.hpp
    header/hand.hpp
    header/dealer.hpp
    header/player.hpp
    src/card.cpp
    src/deck.cpp
    src/hand.cpp
    src/dealer.cpp
    src/player.cpp
    test/cardTest.cpp
    test/dealerTest.cpp
    test/deckTest.cpp
    test/handTest.cpp
    test/playerTest.cpp
)


#links
target_link_libraries(cardTest gmock gtest gtest_main)
target_link_libraries(deckTest gmock gtest gtest_main)
target_link_libraries(handTest gmock gtest gtest_main)
target_link_libraries(dealerTest gmock gtest gtest_main)
target_link_libraries(playerTest gmock gtest gtest_main)
target_link_libraries(game gmock gtest gtest_main)
target_link_libraries(valgrindTestFiles gmock gtest gtest_main)