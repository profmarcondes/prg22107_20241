#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {

    string _name;
    int    _times;
    int    _wins;
    int    _score;

public:
	Player();

    char askLetter();
    void printStats();
    void updateStats(bool result, int score);
};


#endif // PLAYER_H