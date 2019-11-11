//
// Created by Jeffrey and Darren on 11/5/2019.
//
#include <string>
#include <vector>
#include "card.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Player::Player() {
    myName = "Chad"; // our default constructor but never used in our driver
}

void Player::addCard(Card c) {
    myHand.push_back(c);//we use the build in push methods that are within the vector class
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2); //both cards are booked individually instead of as a pair to make things easier
}

bool Player::checkHandForBook() { //we changed this function's signature so that we call it once and it checks for any books.
    bool found = false; //if there are no pairs found, this variable remains unchanged.
    for(int i = 0; i < myHand.size(); i++){
        for(int j = i + 1;j<myHand.size();j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                bookCards(myHand[i],myHand[j]);
                found = true; //this allows for multiple books to be found instead of having to call the function multiple times.
            }
        }
    }
    if(found) { //we remove after finding the books as to not mess up the indices in our nested for loops
        for (int i = 0; i < myBook.size(); i++) {
            removeCardFromHand(myBook[i]);
        }
    }
    return found;
}

bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size();i++){
        if(myHand[i]== c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for(int i = 0; i < myHand.size();i++){
        if(myHand[i]==c){
            myHand.erase(myHand.begin()+i);
            return c;
        }
    }
    return c;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

string Player::showHand() const {
    string hand;
    for(int i = 0; i < myHand.size(); i++){
        hand = hand + myHand[i].toString() + " ";
    }
    return hand; //returns a string instead of actually showing the hand so it can be fed into the oFile or cout depending on the driver
}

string Player::showBooks() const {
    string books;
    for(int i = 0; i < myBook.size(); i++){
        books = books + myBook[i].toString() + " ";
    }
    return books; //same comment as in showHand
}

bool Player::sameRankInHand(Card c) const { //this is the main function we use when checking for matching cards in the driver
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    return myHand[rand()%myHand.size()]; //rand used so that the same card rank isn't asked for every time.   
}
