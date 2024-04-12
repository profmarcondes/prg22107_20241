#ifndef HANGMAN_H
#define HANGMAN_H

#include <set>
#include "dictionary.h"
#include "word.h"
#include "player.h"

using namespace std;

class Hangman {
    Player      _player;
    Dictionary  _dictionary;
    Word        _hang_word;
    set<char>   _errors;

public:
    Hangman(): _hang_word("-","-") { }
    bool play();
    void printStats() { _player.printStats(); }

private:
    void updateError(char letter) { _errors.insert(letter); }
    int  gameScore();
    void showErrors();

};


#endif // HANGMAN_H