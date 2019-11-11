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
    p1.checkHandForBook(); //check the original hands for books
    p2.checkHandForBook();
    oFile<< endl << "Let the game begin: " <<endl;
    cout << "Playing game..." << endl;
    while(d.size() || p1.getHandSize() || p2.getHandSize()) {
        oFile << endl << "NEW ROUND..." << endl;
        oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;
        Card c = p2.chooseCardFromHand();
        oFile << "Chad asks Brad: Do you have any " << c.rankString(c.getRank()) << "'s?" << endl;
        if (p1.sameRankInHand(c)) {
            for (int i = 0; i < 4; i++) {
                Card c2(c.getRank(), (Card::Suit) i);
                if (p1.cardInHand(c2)) {
                    p2.addCard(p1.removeCardFromHand(c2));
                    p2.checkHandForBook();
                    if((p1.getHandSize() == 0 )&&(d.size() > 0))
                        p1.addCard(d.dealCard());
                    if((p2.getHandSize() == 0 )&&(d.size() > 0))
                        p2.addCard(d.dealCard());
                }
            }
        }
        else {
            oFile << "Go Fish!" << endl;
            p1.addCard(d.dealCard());
            p1.checkHandForBook();
            if((p1.getHandSize() == 0 )&&(d.size() > 0))
                p1.addCard(d.dealCard());
        }
	oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;
        if(p2.getHandSize() != 0) {
            c = p2.chooseCardFromHand(); //we use our choose card function to make the game more random
            oFile << "Brad asks Chad: Do you have any " << c.rankString(c.getRank()) << "'s?" << endl;
            if (p1.sameRankInHand(c)) { //the suit doesn't matter for the check so we only need to compare the ranks
                for (int i = 0; i < 4; i++) {
                    Card c2(c.getRank(), (Card::Suit) i);
                    if (p2.cardInHand(c2)) {
                        p1.addCard(p2.removeCardFromHand(c2));
                        p1.checkHandForBook(); //this check is in case the drawn card matches a rank in the player's hand
                        if ((p1.getHandSize() == 0) && (d.size() > 0)) //after all checks for books we make sure the players hand is not empty
                            p1.addCard(d.dealCard());
                        if ((p2.getHandSize() == 0) && (d.size() > 0))
                            p2.addCard(d.dealCard());
                    }
                }
            } else {
                oFile << "Go Fish!" << endl; 
                p2.addCard(d.dealCard());
                p2.checkHandForBook(); //check for books based on the new card and draw another card if their hand is empty afterward
                if ((p2.getHandSize() == 0) && (d.size() > 0))
                    p2.addCard(d.dealCard());
            }
        }
        oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;
        oFile << p1.getName() << " has books: " << p1.showBooks() << endl;
        oFile << p2.getName() << " has books: " << p2.showBooks() << endl;//we show the books at the end of each round instead of at the end of each turn to save space

    }
    oFile << endl;
    oFile << "GAME ENDED, RESULTS: " << endl;
    if(p1.getBookSize() > p2. getBookSize()){
	oFile << p1.getName() << " won with " << p1.getBookSize()/2 << " books!";
    }
    else {
        oFile << p2.getName() << " won with " << p2.getBookSize()/2 << " books!";
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



