//
// Created by Jeffrey and Darren on 11/5/2019.
//
#include "deck.h"
#include "card.h"
#include <ctime>
#include <cstdlib>
using namespace std;
Deck::Deck() {
    srand((unsigned)time(0)); //seeding the random function so we can implement shuffle and chooseCardFromHand
    myIndex = 0; //we start our index at the top of the deck(vector) and work down instead of up.
    int index = 0;
    for(int suit = 0;suit<4;suit++){
        for(int rank = 1; rank < 14;rank++){
            Card c(rank,(Card::Suit)suit);//since suit is and enum we can assign a number instead of saying "spades" or "hearts"
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
        swapIndex2 = (rand() % SIZE); //we are using a constant variable included in deck.h
        tempC = myCards[swapIndex1];
        myCards[swapIndex1] = myCards[swapIndex2];
        myCards[swapIndex2] = tempC;
    }
}

Card Deck::dealCard() {
    myIndex++;
    return myCards[myIndex-1]; //this is written in a way that reduces the lines of code needed 
}

int Deck::size() const {
    return (52 - myIndex);
}

