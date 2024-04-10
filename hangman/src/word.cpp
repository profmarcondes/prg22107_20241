#include "word.h"

Word::Word(string word, string hint): _visible(word.size(), '-') {
    _word = word;
    _hint = hint;
}

bool Word::hasLetter(char letter){
    bool result = false;

    size_t pos = _word.find(letter);
    while(pos != string::npos){
        _visible[pos] = letter;
        result = true;
        pos = _word.find(letter, pos+1);
    }

    return result;
}
    
int  Word::missing(){

}
    
void Word::print(){

}

int  Word::size(){
    _word.size();
}