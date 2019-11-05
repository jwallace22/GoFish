//
// Created by Jeffrey on 11/5/2019.
//
#include "card.h"
#include <string>
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
        default: rank = to_string(myRank);
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
