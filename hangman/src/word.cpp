#include "word.h"

Word::Word(string word, string hint): _visible(word.size(), '-') {
    _word = word;
    _hint = hint;
    _missing = _word.size();
}

bool Word::hasLetter(char letter){
    bool result = false;

    size_t pos = _word.find(letter);
    while(pos != string::npos){
        _visible[pos] = letter;
        _missing--;
        result = true;
        pos = _word.find(letter, pos+1);
    }

    return result;
}
    
int  Word::missing(){
    return _missing;
}
    
void Word::print(){
    cout << "Secret word: " << _visible << endl;
    cout << "Word size: " << size() << ", Hint: " << _hint << endl;
}

unsigned int  Word::size(){
    return _word.size();
}