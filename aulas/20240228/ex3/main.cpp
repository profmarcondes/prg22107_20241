#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Car{
    float _distance;
    float _fuel_level;
    float _tank_size;
    float _consumption;

public:

    Car(float capacity, float consumption);

    void toFuel(float l);
    void drive(float distance);
    void displayInfos();
};


int main(){
    Car car1(40, 12);
    Car car2(50, 14);

    car1.toFuel(20);
    car2.toFuel(30);

    car1.drive(200);
    car2.drive(350);

    cout << "Car 1: " << endl;
    car1.displayInfos();
    cout << "Car 2: " << endl;
    car2.displayInfos();
}
