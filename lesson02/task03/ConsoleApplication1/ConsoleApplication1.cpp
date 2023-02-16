// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct city
{
    std::string name;
    std::string street;
    int building;
    int postcode;
};

void print_data(city x)
{
    std::cout << "the city`s name " << x.name << "\n";
    std::cout << "street " << x.street << "\n";
    std::cout << "street " << x.building << "\n";
    std::cout << "postcode " << x.postcode << "\n";
}

int main()
{
    city urengoy{ "New Urengoy", "Moskowskaya st",20,629300 };
    city kogalym{ "Kogalym","Mira",12,628481 };
    print_data (urengoy );
    print_data(kogalym);
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
