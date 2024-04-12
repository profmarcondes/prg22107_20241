#include "hangman.h"

bool Hangman::play(){
    char guess;
    bool result;

    _hang_word = _dictionary.select();
    _errors.clear();

    while(_errors.size() <= 5 && _hang_word.missing()) {
        _hang_word.print();
        guess = _player.askLetter();
        result = _hang_word.hasLetter(guess);   
        if(!result){
            updateError(guess);
            showErrors();
        }
    }

    if(_hang_word.missing())
        result = false;
    else
        result = true;

    _player.updateStats(result, gameScore());

    return result;

}

int  Hangman::gameScore() {
    int points;

    points = _hang_word.size() - _errors.size();
    if(points < 0)
        points = 0;

    return points;
}

void Hangman::showErrors(){
    cout << "Wrong letter: ";
    for (auto letter : _errors) {
        cout << letter << " ";
    }
    cout << endl;

}