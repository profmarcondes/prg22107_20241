#include "dictionary.h"

Dictionary::Dictionary() {
    srand(time(NULL));

    //Criar as palavras
    
}

Word Dictionary::select(){
    int index;
    index = rand() % _list.size();    
    return _list[index];
}