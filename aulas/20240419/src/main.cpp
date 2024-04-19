#include <iostream>
#include <vector>

using namespace std;

class PaintCost {
	public:
		PaintCost(double cost){
			_cost_per_m2 = cost;
			cout << "PaintCost(" << _cost_per_m2 << ") constructed!" << endl;
		}

		double getCost(double area) {
			return area * _cost_per_m2;
		}

	private:
		double _cost_per_m2;
};

class Shape {
	public:
		//Shape(): _paintcost(70.0) { }
		Shape(double cost = 70.0): _paintcost(cost) { }

		double cost() {
			//cout << "Shape::cost() called !!" << endl;
			return _paintcost.getCost(area());
		}

		virtual double area() = 0;
		virtual void info() = 0;

	private:
		PaintCost _paintcost;
};

class Rectangle: public Shape {
	public:
		Rectangle(double w, double h) {
			_width = w;
			_height = h;
			cout << "Rectangle(" << _width << "," << _height << ") constructed!" << endl;
		}

		void setWidth(double arg) { _width = arg; }
 		void setHeight(double arg) { _height = arg; }

		double area(){
			//cout << "Rectangle::area() called !!" << endl;
			return _width * _height;
		}

		void info() {
			cout << "Rectangle(" << _width << "," << _height << ")" << endl;
		}

	private:
		double _width;
		double _height;
};

class Circle: public Shape {
	public:
		Circle(double r) {
			_radius = r;
			cout << "Circle(" << _radius << ") constructed!" << endl;
		}

		void setRadius(double arg) { _radius = arg; }
 		
		double area(){
			//cout << "Circle::area() called !!" << endl;
			return _radius * _radius * 3.14159;
		}

		void info() {
			cout << "Circle(" << _radius << ")" << endl;
		}

	private:
		double _radius;
};

class TriangleEquilateral: public Shape {
	public:
		TriangleEquilateral(double w) {
			_width = w;
			cout << "TriangleEquilateral(" << _width << ") constructed!" << endl;
		}

		void setWidth(double arg) { _width = arg; }
 		
		double area(){
			return _width * _width * 0.433013;
		}

		void info() {
			cout << "TriangleEquilateral(" << _width << ")" << endl;
		}

	private:
		double _width;
};


int main() {

	std::cout << "Hello, Heranca!!!" << std::endl;

	vector<Shape *> canvas;

	canvas.push_back(new Rectangle(7.89, 4.67));
	canvas.push_back(new Circle(5.0));
	canvas.push_back(new TriangleEquilateral(4.5));
	canvas.push_back(new Circle(1.75));
	canvas.push_back(new TriangleEquilateral(7.5));
	canvas.push_back(new Rectangle(2, 4));
	
	double totalArea;
	double totalCost;

	cout << "====================================" << endl;

	for(auto shape: canvas){
		shape->info();
		cout << "Area = " << shape->area() << ", Cost = " << shape->cost() << endl;
		totalArea += shape->area();
		totalCost += shape->cost();
	}

	cout << "Total Area = " << totalArea << endl;
	cout << "Total Cost = " << totalCost << endl;
	cout << "====================================" << endl;

	Rectangle rect(7.89, 4.67);
	Circle circle(5.0);

	cout << "Obj area == " << rect.area() << endl;
	cout << "Paint cost == " << rect.cost() << endl;

	rect.info();

	Shape * ptr = &rect;
	cout << "Rectangle Area == " << ptr->area() << endl;

	cout << "ptr changed!" << endl;
	ptr = &circle;
	cout << "Circle Area == " << ptr->area() << endl;




	return 0;
}