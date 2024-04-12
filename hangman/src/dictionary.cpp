#include "dictionary.h"

Dictionary::Dictionary() {
    srand(time(NULL));
    //Criar as palavras
    add(Word("tubarao","animal"));
    add(Word("cadeira","objeto"));
    add(Word("vermelho","cor"));
    add(Word("florianopolis","cidade"));
}

Word Dictionary::select(){
    int index;
    index = rand() % _list.size();    
    return _list[index];
}