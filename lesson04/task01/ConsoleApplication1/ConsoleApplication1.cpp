// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale.h>
class Address
{
private:
    std::string city;
    std::string street;
    int home;
    int apt;
public:
    Address() { this->city = "none"; this->street = "none";
    this->home = 0; this-> apt = 0;  }
    Address(std::string a, std::string b, int c,int d)
    {
        this->city = a; this->street = b;
        this->home = c; this->apt = d;
    }
    std::string get_address()
    {
        return city + "\n"+ street +"\n" + std::to_string(home)+"\n"
            + std::to_string(apt)+"\n";
           }
    std::string get_address_for_out()
    {
        return city + ", " + street + ", " + std::to_string(home) + ", "
            + std::to_string(apt) + "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::fstream in;
    in.open("in.txt");
    if (in)
    {
        std::cout << "file open\n";
    }

    else
    {
        std::cout << "file corrupted or nothing";
        return 0;
    }
    int size;
    in >> size;
    Address* array=new Address [size];
    for (int i = 0; i < size; i++)
    {
        std::string a, b;
        int c, d;
        in >> a;
        in >> b;
        in >> c;
        in >> d;
        array[i] =  Address(a, b, c, d);
    }
    in.close();
    for (int i=0;i<size;i++)
    std::cout << array[i].get_address();
    std::fstream out;
    out.open("out.txt", std::ios::out);
    out << size << "\n";
    for (int i = size - 1; i >= 0; i--) {
        out << array[i].get_address_for_out();
        std::cout << array[i].get_address_for_out();
    }
    delete[] array;
    array = nullptr;
    out.close();
    return 0;
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
