// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Calculator
{
private:
    double num1;
    double num2;
public:
    Calculator()
    {
        num1 = 0;
        num2 = 0;
    }
    double add() { return this->num1 + this->num2; }
    double multiply() { return this->num1 * this->num2; }
    double subtract_1_2() { return this->num1 - this->num2; }
    double subtract_2_1() { return this->num2 - this->num1; }
    double divide_1_2() { return this->num1 / this->num2; }
    double divide_2_1() { return this->num2 / this->num1; }
    bool set_num1(double x) {
        //double a = x;
        if (x == 0) return false;
        this->num1 = x;
        return true;
    }
    bool set_num2(double x) {
        //double a = x;
        if (x == 0) return false;
        this->num2 = x;
        return true;
    }
};

int main()
{
    Calculator calc;
    
    double a;
mark01:
    std::cout << "Enter num1: ";
    std::cin >> a;
    if (calc.set_num1(a) != true) { std::cout << "Wrong input\n"; goto mark01; }
mark02:
    std::cout << "Enter num2: ";
    std::cin >> a;
    if (calc.set_num2(a) != true) { std::cout << "Wrong input\n"; goto mark02; }
    std::cout << "num1 + num2 = "<<calc.add()<<"\n";
    std::cout << "num1 - num2 = " << calc.subtract_1_2() << "\n";
    std::cout << "num2 - num1 = " << calc.subtract_2_1() << "\n";
    std::cout << "num1 * num2 = " << calc.multiply() << "\n";
    std::cout << "num1 / num2 = " << calc.divide_1_2() << "\n";
    std::cout << "num2 / num1 = " << calc.divide_2_1() << "\n";
    goto mark01;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
