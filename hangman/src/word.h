#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word {
    string _word;
    string _hint;
    string _visible;

public:
	Word(string word, string hint);

    bool hasLetter(char letter);
    int  missing();
    void print();
    int  size();
};


#endif // WORD_H