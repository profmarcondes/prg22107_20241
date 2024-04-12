#ifndef WORD_H
#define WORD_H

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Word {
    string _word;
    string _hint;
    string _visible;
    int    _missing;

public:
	Word(string word, string hint);

    bool hasLetter(char letter);
    int  missing();
    void print();
    unsigned int  size();
};


#endif // WORD_H