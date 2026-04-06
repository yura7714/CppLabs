#include <iostream>
#include <cstring>

using namespace std;

class Person {
    public:
        string name;
        int age;
        string gender;
        Person(string name, int age, string gender);
        virtual void sleep() = 0;
        virtual void sit() = 0;
};

class Driver: public Person {
    public:
        int drivingExperience;
        Driver(string name, int age, string gender, int drivingExperience);
        virtual void sleep();
        virtual void sit();
};

class Trucker: public Driver {
    public:
        int deliveriesCount;
        Trucker(string name, int age, string gender, int drivingExperience, int deliveriesCount);
        virtual void sleep();
        virtual void sit();
};

Person::Person(string name, int age, string gender) {
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void Person::sleep() {
    cout << "Человек спит... (функция деда)" << endl;
}

void Person::sit() {
    cout << "Человек сидит... (функция деда)" << endl;
}

Driver::Driver(string name, int age, string gender, int drivingExperience): Person(name, age, gender) {
    this->drivingExperience = drivingExperience;
}

void Driver::sleep() {
    Person::sleep();
    cout << "Водитель спит... (функция отца)" << endl;
}

void Driver::sit() {
    Person::sit();
    cout << "Водитель сидит... (функция отца)" << endl;
}

Trucker::Trucker(string name, int age, string gender, int drivingExperience, int deliveriesCount): Driver(name, age, gender, drivingExperience) {
    this->deliveriesCount = deliveriesCount;
}

void Trucker::sleep() {
    Driver::sleep();
    cout << "Дальнобойщик спит... (функция сына)" << endl;
}

void Trucker::sit() {
    Driver::sit();
    cout << "Дальнобойщик сидит... (функция сына)" << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Driver driver("Илья", 38, "муж", 14);
    Trucker trucker("Михаил", 41, "муж", 23, 704);

    cout << "sleep() для Driver:" << endl;
    driver.sleep();

    cout << "sleep() для Trucker:" << endl;
    trucker.sleep();

    cout << "sit() для Driver:" << endl;
    driver.sit();

    cout << "sit() для Trucker:" << endl;
    trucker.sit();

    return 0;
}