#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Circle{
    private:
        float _radius;
        float _pos_x;
        float _pos_y;

        float area(){ return M_PI * _radius * _radius; }
        float perimeter(){ return  2 * M_PI * _radius; }

    public:

        float distanceTo(const Circle obj) { return sqrt( pow((obj._pos_x - _pos_x), 2) + pow((obj._pos_y - _pos_y), 2));}
        void radius(float r){ _radius = r; }
        void scale(float percentage) { _radius += _radius * (percentage/100); }

        void setPosition(float x, float y) {
            _pos_x = x;
            _pos_y = y;
        }

        void printRadius(){ cout << "Radius: " << _radius << endl; }
        void printCenter(){ cout << "X center: " << _pos_x << endl << "Y center: " << _pos_y << endl; }
        void printArea(){ cout << "Area: " << area() << endl; }

};      

int main()
{
    Circle circle1;
    cout << "Circle 1:" << endl;
    circle1.radius(3);
    circle1.printRadius();
    circle1.printArea();
    circle1.setPosition(3, 4);
    circle1.printCenter();
    circle1.scale(10);
    circle1.printRadius();
    circle1.printArea();

    cout << endl;
    cout << "Circle 2:";

    Circle circle2;
    circle2.radius(2);
    circle2.printRadius();
    circle2.printArea();
    circle2.setPosition(0, 0);
    circle2.printCenter();
    circle2.scale(50);
    circle2.printRadius();
    circle2.printArea();
    
    float dist = circle1.distanceTo(circle2);

    cout << endl << "Distance between circle1 and circle2 is " << dist << endl;

}