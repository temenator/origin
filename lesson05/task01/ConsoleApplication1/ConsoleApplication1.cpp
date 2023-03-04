

#include <iostream>
#include <sstream>
#include <fstream>

class Figure
{
public:
    int get_side_count() { return sides_cout; }
    std::string get_name() { return name; }
    Figure() { this->name = "Figure"; this->sides_cout = 0; }
protected:
    int sides_cout;
    std::string name;
    };
class Triangle :public Figure
{
public:
    Triangle() { this->name = "Triangle"; this->sides_cout = 3; }
};
class Quadrangle :public Figure
{
public:
    Quadrangle() { this->name = "Quadrangle"; this->sides_cout = 4; }
};

int main()
{
    Figure a;
    Triangle b;
    Quadrangle c;
    std::cout << "Sides count:\n";
    std::cout << a.get_name() << ": " << a.get_side_count() << "\n";
    std::cout << b.get_name() << ": " <<b.get_side_count() << "\n";
    std::cout << c.get_name() << ": " << c.get_side_count() << "\n";
}

