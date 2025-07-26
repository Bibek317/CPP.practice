#include <iostream>

class Animal {
public:
    std::string name;
    int weight;

    Animal(std::string name, int weight) {
        this->name = name;
        this->weight = weight;
        std::cout << "The name of pig 🐖 is " << this->name << " and weight is " << this->weight << std::endl;
    }

    void sound() {
        std::cout << "The " << this->name << " says: we wee" << std::endl;
    }

    int mass() {
        return (weight <= 100) ? weight * 2 : weight * 10;
    }
};

int factorial(int n) {
    if (n < 0) {
        std::cerr << "Factorial is not defined for negative numbers!" << std::endl;
        return -1;
    }
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    std::cout << "Hello, C++!" << std::endl;

    Animal pig("Tom", 60);
    pig.sound();

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int fact = factorial(num);
    if (fact != -1)
        std::cout << "The factorial of " << num << " is " << fact << std::endl;

    std::cout << "The mass of the pig is " << pig.mass() << std::endl;
    

    return 0;
}
