#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Die {
private:
	int _faceValue;

public:
	Die(unsigned int seed);
	int getFaceValue() { return _faceValue; }
	void roll() {
		_faceValue = ( rand() % 6 ) + 1;
		cout << this << " = " << _faceValue << endl;
	};
};

Die::Die(unsigned int seed){
	cout << "Constructing Die " << this << endl;
	srand(seed);
	roll();
}

class DiceGame {
private:
	Die _die1;
	Die _die2;

public:
	DiceGame(): _die1(time(NULL)), _die2(time(NULL)+1) { 
		cout << "Constructing DiceGame" << endl;
	}
	bool play();
};

bool DiceGame::play(){
	int fv1, fv2;
	int result;

	_die1.roll();
	fv1 = _die1.getFaceValue();

	_die2.roll();
	fv2 = _die2.getFaceValue();

	result = fv1 + fv2;

	if ( result == 7 ){
		return true;
	} else {
		return false;
	}
}

int main() {

	DiceGame game;

	int times = 10;
	int wins = 0;
	for(int i = 0; i < times; i++){
		if(game.play()){
			cout << "You win!" << endl;
			wins++;
		} else {
			cout << "You lose!" << endl;
		}
	}

	float win_percentage = wins/(float)times;
	cout << "Win percentage = " << win_percentage << endl;

}
