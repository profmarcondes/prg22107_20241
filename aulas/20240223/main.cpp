#include <iostream>
#include <string>

using namespace std;

class World {
private:
	string _name;

public:
	World(string p1) { _name = p1; }
	//void name(string p1) { _name = p1; }
	void sayIt();

};

void World::sayIt() {
	
	cout << "Hello " << _name << "! (" << this << ")" << endl;
}

int main() {

	World obj1("Earth");
	obj1.sayIt();

	World obj2("Mordor");
	obj2.sayIt();


}
