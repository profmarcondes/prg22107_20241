#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Box {
	public:
		Box(double lenght, double breadth, double height){
			_lenght = lenght;
			_height = height;
			_breadth = breadth;
		}

		Box(){
			_lenght = 1.0;
			_height = 1.0;
			_breadth = 1.0;
		}

		Box operator+(const Box& arg){
			Box result;
			result._lenght = this->_lenght + arg._lenght;
			result._breadth = this->_breadth + arg._breadth;
			result._height = this->_height + arg._height;
			return result;
		}


		double volume() const {
			return _lenght * _height * _breadth;
		}

		friend ostream& operator<<(ostream& out, const Box& b) {
			out << "Box(" << b._lenght << ",";
			out << b._breadth << "," << b._height;
			out << ") = " << b.volume() ;
			return out;
		}

	private:
		double _lenght;
		double _breadth;
		double _height;
}; 


bool operator<(const Box& arg1, const Box& arg2){
	return arg1.volume() < arg2.volume();
}

int main() {
	cout << "Hello, boxes!!!" << endl;

	Box a(2.0, 4.5, 5.0);
	Box b(0.5, 0.25, 0.25);
	Box c;

	vector<Box> boxes;

	boxes.push_back(a);
	boxes.push_back(b);
	boxes.push_back(c);
	
	for(auto box: boxes){
		cout << box << endl;
	}

	c = a + b;
	cout << "Caixa C depois da soma = " << c << endl;
	boxes[2] = c;

	sort(boxes.begin(), boxes.end());

	for(auto box: boxes){
		cout << box << endl;
	}
	
	return 0;
}