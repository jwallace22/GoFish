//
// Created by Jeffrey on 11/5/2019.
//
#include "card.h"
#include <string>
#include <iostream>
using namespace std;
Card::Card() {
    myRank = 1; //the default card is an Ace of spades
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank; //initialize the card with the parameters passed
    mySuit = s;
}

string Card::toString() const {
    string suit = suitString(mySuit);
    string rank = rankString(myRank);
    return(rank + suit); //the 2 strings are added to create a 2 character string such as As for ace of spades
}

bool Card::sameSuitAs(const Card &c) const {
    return(mySuit == c.getSuit()); 
}

string Card::suitString(Card::Suit s) const {
    string suit;
    switch(s){ //switch statement based on the input suit since the types were enumerated and finite
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
        case 4: rank = "4"; // this switch statement was used because stoi was giving us issues on linux. 
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
