//
// Created by Jeffrey on 11/5/2019.
//
#include "card.h"
#include <string>
#include <iostream>
using namespace std;
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string suit = suitString(mySuit);
    string rank = rankString(myRank);
    return(rank + suit);
}

bool Card::sameSuitAs(const Card &c) const {
    return(mySuit == c.getSuit());
}

string Card::suitString(Card::Suit s) const {
    string suit;
    switch(s){
        case spades: suit = "s";
            break;
        case hearts: suit = "h";
            break;
        case diamonds: suit = "d";
            break;
        case clubs: suit = "c";
            break;
    }
    return suit;
}

string Card::rankString(int r) const {
    string rank;
    switch(r){
        case 1: rank = "A";
            break;
        case 11: rank = "J";
            break;
        case 12: rank = "Q";
            break;
        case 13: rank = "K";
            break;
        case 2: rank = "2";
            break;
        case 3: rank = "3";
            break;
        case 4: rank = "4";
            break;
        case 5: rank = "5";
            break;
        case 6: rank = "6";
            break;
        case 7: rank = "7";
            break;
        case 8: rank = "8";
            break;
        case 9: rank = "9";
            break;
        case 10: rank = "10";
            break;

    }
    return rank;
}

int Card::getRank() const {
    return  myRank;
}

Card::Suit Card::getSuit() const {
    return mySuit;
}

bool Card::operator==(const Card &rhs) const {
    return((mySuit == rhs.getSuit())&&(myRank==rhs.getRank()));
}
bool Card::operator!=(const Card &rhs) const {
    return(!((mySuit == rhs.getSuit())&&(myRank==rhs.getRank())));
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}
