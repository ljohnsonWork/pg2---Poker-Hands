/*
 Lawrence Johnson
 CS201
 
 PG2.cpp v3 - Poker hands
	
 Code date: 9/25/14 8:16am
 
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PG2.h"
using namespace std;

int main(int argc, char **argv){
    // Build deck
    int sz = 52;
    int *deck = new int[sz];
    for (int i = 0; i < sz; i++) deck[i] = i;
    
    // Create players variables
    int handsz = 5;
    int numPlayers = 10;    // Do not set above 10
    
    // Set seed to generate random numbers
    srand(time(NULL));
    
    // Shuffle and deal cards
    deal(deck, sz);
    
    // Proccess players hands
    for (int i = 0; i < numPlayers; ++i) {
        int spot = i * 5;
        players(&deck[spot], handsz);
    }
    
    delete[] deck;
    return 0;
}

// Randomize deck
// V2 - allowed card to swap with itself by adding
// an "=" to count < sz;
// V3 - Removed V2 change and Change was made to the
// random numbers selection. By adding 1 to my count,
// will allow for the correct number of cards to pick
// from.
void deal(int *deck, int sz){
    for (int count = 1; count < sz; ++count){
        int random = deck[(rand() % (count + 1))];
        int hold = deck[count];
        deck[count] = deck[random];
        deck[random] = hold;
    }
}

// Print deck or players hand to screen
/*  A  2  3  4  5  6  7  8  9  10 J  Q  K
 H  00 01 02 03 04 05 06 07 08 09 10 11 12
 C  13 14 15 16 17 18 19 20 21 22 23 24 25
 D  26 27 28 29 30 31 32 33 34 35 36 37 38
 S  39 40 41 42 43 44 45 46 47 48 49 50 51
 
 p0 00-04, p1 05-09, p2 10-14, p3 15-19, p4 20-24
 p5 25-29, p6 30-34, p7 35-39, p8 40-44, p9 45-49
 */
void printDeck(int *deck, int sz){
    for (int i = 0; i < sz; ++i){
        int suit = deck[i] / 13;
        int val = deck[i] % 13;
        switch (val){
            case(0) : cout << "ACE "; break;
            case(1) : cout << "TWO "; break;
            case(2) : cout << "THREE "; break;
            case(3) : cout << "FOUR "; break;
            case(4) : cout << "FIVE "; break;
            case(5) : cout << "SIX "; break;
            case(6) : cout << "SEVEN "; break;
            case(7) : cout << "EIGHT "; break;
            case(8) : cout << "NINE "; break;
            case(9) : cout << "TEN "; break;
            case(10) : cout << "JACK "; break;
            case(11) : cout << "QUEEN "; break;
            case(12) : cout << "KING "; break;
        }
        switch (suit){
            case(0) : cout << "OF HEARTS\n"; break;
            case(1) : cout << "OF CLUBS\n"; break;
            case(2) : cout << "OF DIAMONDS\n"; break;
            case(3) : cout << "OF SPADES\n"; break;
        }
    }
    cout << endl;
}

// Sort card from low (Ace) to high (King) using basic bubble sort.
void sort(int *D, int sz){
    for (int i = 0; i < sz; ++i){
        for (int j = i + 1; j < sz; j++){
            if (D[i]%13 > D[j]%13){
                int temp = D[i];
                D[i] = D[j];
                D[j] = temp;
            }
        }
    }
}

// Check players hands and print out results
void players(int *hand, int handsz){
    int matching = 0;
    int pairs = 0;
    int trip = 0;
    int four = 0;
    
    // Print Hand and than sort cards for checking hand
    printDeck(hand, handsz);
    sort(hand, handsz);
    
    // Check hand for pair, 2 pair, 3 of a kind, fullhouse, or 4 of a kind.
    for (int card = 0; card < handsz; ++card) {
        for (int check = card+1; check < handsz; ++check) {
            // Check if current card and next card match.
            // If so, ad on to current matching cards and
            // advance the spot of card to not double check.
            if (hand[card]%13 == hand[check]%13){
                matching++;
                card++;
            }
            // If no match found on current run, proccess
            // current value of match and add one to the
            // corresponding hand.
            else{
                card = check;
                switch (matching){
                    case(1) : ++pairs; break;
                    case(2) : ++trip; break;
                    case(3) : ++four; break;
                }
                matching = 0;
            }
        }
        // Proccess remaining matches.
        switch (matching){
            case(1) : ++pairs; break;
            case(2) : ++trip; break;
            case(3) : ++four; break;
        }
    }
    
    // Print out results
    if (pairs == 0 && trip == 0 && four == 0) cout << "NOTHING\n\n\n";
    else if (pairs == 1 && trip == 0 && four == 0) cout << "ONE PAIR\n\n\n";
    else if (pairs == 2 && trip == 0 && four == 0) cout << "TWO PAIR\n\n\n";
    else if (pairs == 0 && trip == 1 && four == 0) cout << "THREE OF A KIND\n\n\n";
    else if (pairs == 1 && trip == 1 && four == 0) cout << "FULL HOUSE\n\n\n";
    else if (pairs == 0 && trip == 0 && four == 1) cout << "FOUR OF A KIND\n\n\n";
    
}
