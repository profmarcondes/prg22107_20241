#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include "word.h"

using namespace std;

class Dictionary
{
    vector<Word> _list;

public:
	Dictionary();

    Word select();

    void add(Word word) {
        _list.push_back(word);
    };

};


#endif // DICTIONARY_H