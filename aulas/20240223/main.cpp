#include <iostream>
#include <string>

using namespace std;

class World {
private:
	string _name;

public:
	World(string name);
	void name(string p1) { _name = p1; }
	string name() { return _name; } 
	void sayIt();
	~World() { cout << "Goodbye " << _name << "! (" << this << ")" << endl; }

};

World::World(string name){
	_name = name;
	cout << "Constructing world " << _name <<  "! (" << this << ")" << endl;
}

void World::sayIt() {
	
	cout << "Hello " << _name << "! (" << this << ")" << endl;
}

World gbl_obj("Global");

void func1() {

    World obj1("Earth");
	obj1.sayIt();

	gbl_obj.sayIt();

	cout << "Leaving func1()" << endl;

}

int main() {

	cout << "Calling func1()" << endl;
	func1();

	World obj2("Mordor");
	obj2.sayIt();

	World * obj3;
	obj3 = new World("Dynamic");

	obj3->sayIt();

	cout << obj3->name() << endl;

	obj3->name("Dynamic World");

	obj3->sayIt();

	cout << obj3 << endl;

	delete obj3;

	cout << obj3 << endl;

	obj3->sayIt();

	gbl_obj.sayIt();

}
