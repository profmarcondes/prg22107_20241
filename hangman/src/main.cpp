#include <iostream>
#include "hangman.h"

int main() {
	std::cout << "Hello, Hangman!!!" << std::endl;

	Hangman game;

	if(game.play()){
		cout << "Parabéns, você venceu!" << endl;
	} else {
		cout << "Você perdeu!" << endl;
	}
	game.printStats();

	return 0;
}