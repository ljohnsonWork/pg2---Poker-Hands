//
//  pg2.h
//  pg2
//
//  Created by Lawrence Johnson on 9/20/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#ifndef PG2_h
#define PG2_h

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv);
void deal(int *deck, int sz);
void printDeck(int *deck, int sz);
void sort(int *D, int sz);
void players(int *hand, int handsz);

#endif
