#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius;
    double centerX;
    double centerY;

    // M�todos privados para c�lculos
    double calculateArea();
    double calculateDistance(const Circle& otherCircle) const;
    double calculateCircumference() const;


public:
    // M�todos p�blicos
    void setRadius(double newRadius);
    void increaseRadiusByPercent(double percent);
    void setCenter(double x, double y);
    double getDistance(const Circle& otherCircle) const; // M�todo p�blico para acessar calculateDistance
    void printRadius() const;
    void printCenter() const;
    void printArea() const;

};

double Circle::calculateArea() {
    return acos(-1) * radius * radius;
}

double Circle::calculateCircumference() const {
    return 2 * acos(-1) * radius;
}

double Circle::calculateDistance(const Circle& otherCircle) const {
    otherCircle.calculateArea();
    return sqrt(pow(centerX - otherCircle.centerX, 2) + pow(centerY - otherCircle.centerY, 2));
}

void Circle::setRadius(double newRadius) {
    if (newRadius > 0) {
        radius = newRadius;
    } else {
        cout << "Error: Radius must be a positive number." << endl;
    }
}

void Circle::increaseRadiusByPercent(double percent) {
    if (percent > 0) {
        radius *= (1 + percent / 100.0);
    } else {
        cout << "Error: Percentage increase must be a positive number." << endl;
    }
}

void Circle::setCenter(double x, double y) {
    centerX = x;
    centerY = y;
}

double Circle::getDistance(const Circle& otherCircle) const {
    return calculateDistance(otherCircle);
}

void Circle::printRadius() const {
    cout << "Radius: " << radius << endl;
}

void Circle::printCenter() const {
    cout << "Center: (" << centerX << ", " << centerY << ")" << endl;
}

void Circle::printArea() const {
    cout << "Area: " << calculateArea() << endl;
}

int main() {
    Circle circle1;
    circle1.setRadius(3.5);
    circle1.setCenter(0, 0);

    cout << "Circle 1:" << endl;
    circle1.printRadius();
    circle1.printCenter();
    circle1.printArea();

    Circle circle2;
    circle2.setRadius(2.0);
    circle2.setCenter(1, 2);

    cout << "\nCircle 2:" << endl;
    circle2.printRadius();
    circle2.printCenter();
    circle2.printArea();

    double distance = circle1.getDistance(circle2);
    cout << "\nDistance between Circle 1 and Circle 2: " << distance << endl;

    circle1.increaseRadiusByPercent(10);
    cout << "\nAfter increasing the radius of Circle 1 by 10%:" << endl;
    circle1.printRadius();
    circle1.printArea();

    return 0;
}

