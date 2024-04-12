//============================================================================
// Name        : lista01_ex1.cpp
// Author      : Hugo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Pessoa {
	string _nome;
	unsigned int _idade;
	unsigned int _altura; // Em centímetros

public:
	Pessoa(string nome, unsigned int idade, unsigned int altura) {
		_nome = nome;
		_idade = idade;
		_altura = altura;
	}

	string nome() { return _nome; };
	unsigned int idade() { return _idade; };
	unsigned int altura() { return _altura; };

	void idade(unsigned int idade) {
		if(idade > _idade){
			_idade = idade;
		}
	};

	void altura(unsigned int altura) { _altura = altura; };

	void fazAniversario(unsigned int altura = 0){
		_idade++;
		if (altura != 0) {
			_altura = altura;
		}
	}

	void print(){
		cout << "Eu sou o " << _nome;
		cout << ". Tenho " << _idade << " anos e ";
		cout << _altura << " centimetros de altura.";
		cout << endl;
	}
};


int main() {
	cout << "Lista 01 - Exercício 01" << endl; // prints Hello World!

	Pessoa obj1("João", 34, 191);
	Pessoa obj2("Pedro", 23, 175);

	obj1.print();
	obj2.print();

	obj1.fazAniversario();
	obj2.fazAniversario(179);

	obj1.print();
	obj2.print();

	return 0;
}
