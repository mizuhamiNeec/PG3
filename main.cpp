#include <iostream>

// 既定
class Vehicle {
public:
	virtual void Move() const {
		std::cout << "Vehicle is moving" << std::endl;
	}
	virtual ~Vehicle() = default;
};

// 派生
class Car : public Vehicle {
public:
	void Move() const override {
		std::cout << "Car is driving" << std::endl;
	}
};

// 派生
class Bicycle : public Vehicle {
public:
	void Move() const override {
		std::cout << "Bicycle is pedaling" << std::endl;
	}
};

int main() {
	Vehicle* vehicle1 = new Car();
	Vehicle* vehicle2 = new Bicycle();

	vehicle1->Move();
	vehicle2->Move();

	delete vehicle1;
	delete vehicle2;

	return 0;
}