//created by Jeffrey Wallace and Darren Nguyen
//driver file for the GoFish! programming assignment for EE312. Fall 2019.
#include <iostream>    // Provides oFile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    ofstream oFile;
    oFile.open("gofish_results.txt");
    int numCards = 7; //only 2 players so each starts with 7 cards 
    cout << "Starting game" << endl;
    Player p1("Brad");
    Player p2("Chad");

    Deck d;  //create a deck of cards
    d.shuffle(); //shuffle outside of the constructor so the code is more reusable

    dealHand(d, p1, numCards); //using the deal hand function given in the source code
    dealHand(d, p2, numCards);

    oFile << p1.getName() << " starting hand is : " << p1.showHand() << endl;
    oFile << p2.getName() << " starting hand is : " << p2.showHand() << endl;

    oFile<< endl << "Let the game begin: " <<endl;
    cout << "Playing game..." << endl;
    while(d.size() || p1.getHandSize() || p2.getHandSize()) {
        Card c, temp;
        p1.checkHandForBook();
        if(p1.getHandSize() > 0) {
            c = p1.chooseCardFromHand(); //we use our choose card function to make the game more random
            oFile << "Brad: Chad, do you have any " << c.rankString(c.getRank()) << "'s?" << endl;
            if (p2.sameRankInHand(c)) { //the suit doesn't matter for the check so we only need to compare the ranks
                for (int i = 0; i < 4; i++) {
                    Card c2(c.getRank(), (Card::Suit) i);
                    if (p2.cardInHand(c2)) {
                        p1.addCard(p2.removeCardFromHand(c2));
                        p1.checkHandForBook(); //this check is in case the drawn card matches a rank in the player's hand
                    }
                }
            } else {
                oFile << "Chad: Go Fish!" << endl;
                temp = d.dealCard();
                p1.addCard(temp);
                oFile << "Brad: draws " << temp <<endl;
            }
        }
        if(p1.getHandSize() == 0 && d.size() > 0) {
            temp = d.dealCard();
            p1.addCard(temp);
            oFile << "Brad: draws " << temp <<endl;
        }
        oFile << p1.getName() << " hand is : " << p1.showHand() << endl;
        oFile << p2.getName() << " hand is : " << p2.showHand() << endl;
        oFile << endl;
        p2.checkHandForBook();
        if(p2.getHandSize() > 0) {
            c = p2.chooseCardFromHand(); //we use our choose card function to make the game more random
            oFile << "Chad: Brad, do you have any " << c.rankString(c.getRank()) << "'s?" << endl;
            if (p1.sameRankInHand(c)) { //the suit doesn't matter for the check so we only need to compare the ranks
                for (int i = 0; i < 4; i++) {
                    Card c2(c.getRank(), (Card::Suit) i);
                    if (p1.cardInHand(c2)) {
                        p2.addCard(p1.removeCardFromHand(c2));
                        p2.checkHandForBook(); //this check is in case the drawn card matches a rank in the player's hand
                    }
                }
            } else {
                oFile << "Brad: Go Fish!" << endl;
                temp = d.dealCard();
                p2.addCard(temp);
                oFile << "Chad: draws " << temp <<endl;
            }
        }
        if(p2.getHandSize() == 0 && d.size() > 0) {
            temp = d.dealCard();
            p2.addCard(temp);
            oFile << "Chad: draws " << temp <<endl;
        }
        oFile << p1.getName() << " hand is : " << p1.showHand() << endl;
        oFile << p2.getName() << " hand is : " << p2.showHand() << endl;
        oFile << p1.getName() << " has books: " << p1.showBooks() << endl;
        oFile << p2.getName() << " has books: " << p2.showBooks() << endl << endl;
    }
    oFile << endl;
    oFile << "GAME ENDED, RESULTS: " << endl;
    if(p1.getBookSize() > p2. getBookSize()){
	oFile << p1.getName() << " won with " << p1.getBookSize()/2 << " books!"<<endl;
    }
    else if(p1.getBookSize() < p2. getBookSize()) {
        oFile << p2.getName() << " won with " << p2.getBookSize()/2 << " books!"<<endl;
    }
    else{
        oFile << "It is a tie!" << endl;
    }
    cout << "The game is over!" << endl;
    oFile.close(); //close the file so we don't get errors later.
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}