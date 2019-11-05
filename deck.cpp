//
// Created by Jeffrey on 11/5/2019.
//
#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>
using namespace std;
Deck::Deck() {
    srand((unsigned)time(0));
    myIndex = 0;
    int index = 0;
    for(int suit = 0;suit<4;suit++){
        for(int rank = 1; rank < 14;rank++){
            Card c(rank,(Card::Suit)suit);
            myCards[index] = c;
            index ++;
        }
    }
}

void Deck::shuffle() {
    int swapIndex1, swapIndex2;
    Card tempC;
    for(int i = 0; i < 5*SIZE; i++) {
        swapIndex1 = (rand() % SIZE);
        swapIndex2 = (rand() % SIZE);
        tempC = myCards[swapIndex1];
        myCards[swapIndex1] = myCards[swapIndex2];
        myCards[swapIndex2] = tempC;
    }
}

Card Deck::dealCard() {
    myIndex++;
    return myCards[myIndex--];
}

int Deck::size() const {
    return (52 - myIndex);
}

