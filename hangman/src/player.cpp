#include "player.h"

Player::Player() {
    cout << "What's your name: ";
    getline(cin, _name);

    _times = 0;
    _wins = 0;
    _score = 0;
}

char Player::askLetter(){
    string input;
    cout << "Say your guess letter: ";
    getline(cin, input);
    return tolower(input[0]);
}

void Player::printStats(){
    cout << _name << " Statistics." << endl;
    cout << " Played " << _times << " times" << endl;
    cout << " Score " << _score << endl;
    cout << " Win percentage " << _wins/(double)_times << endl;
}

void Player::updateStats(bool result, int score){
    _times++;
    if(result){
        _wins++;
        _score += score;
    }
}