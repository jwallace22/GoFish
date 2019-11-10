// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
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
    int numCards = 7;

    Player p1("Brad");
    Player p2("Chad");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    p1.checkHandForBook();
    p2.checkHandForBook();
    oFile<< endl << "Let the game begin: " <<endl;
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
            c = p2.chooseCardFromHand();
            oFile << "Brad asks Chad: Do you have any " << c.rankString(c.getRank()) << "'s?" << endl;
            if (p1.sameRankInHand(c)) {
                for (int i = 0; i < 4; i++) {
                    Card c2(c.getRank(), (Card::Suit) i);
                    if (p2.cardInHand(c2)) {
                        p1.addCard(p2.removeCardFromHand(c2));
                        p1.checkHandForBook();
                        if ((p1.getHandSize() == 0) && (d.size() > 0))
                            p1.addCard(d.dealCard());
                        if ((p2.getHandSize() == 0) && (d.size() > 0))
                            p2.addCard(d.dealCard());
                    }
                }
            } else {
                oFile << "Go Fish!" << endl;
                p2.addCard(d.dealCard());
                p2.checkHandForBook();
                if ((p2.getHandSize() == 0) && (d.size() > 0))
                    p2.addCard(d.dealCard());
            }
        }
        oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;
        oFile << p1.getName() << " has books: " << p1.showBooks() << endl;
        oFile << p2.getName() << " has books: " << p2.showBooks() << endl;

    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



