//
// Created by Jeffrey on 11/5/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player() {
    myName = "Chad";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook() {
    bool found = false;
    for(int i = 0; i < myHand.size(); i++){
        for(int j = i + 1;j<myHand.size();j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                bookCards(myHand[i],myHand[j]);
                found = true;
            }
        }
    }
    if(found) {
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