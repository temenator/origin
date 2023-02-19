// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
enum class months
{
    January=1,
    February=2,
    March=3,
    April=4,
    May=5,
    June=6,
    July=7,
    August=8,
    September=9,
    October=10,
    November=11,
    December=12,
};


int main()
{
    
    int input_val=1;
    while (input_val != 0 )
    {
        std::cout << "Enter  month number, use zero to exit" << "\n";
        std::cin >> input_val;
        months user_month = static_cast<months>(input_val);
        switch(user_month)
        {
 case months::January:  std::cout << "January\n"; break;
 case months::February: std::cout << "February\n"; break;
 case months::March:    std::cout << "March\n"; break;
 case months::April:    std::cout << "April\n"; break;
 case months::May:      std::cout << "May\n"; break;
 case months::June:     std::cout << "June\n"; break;
 case months::July:     std::cout << "July\n"; break;
 case months::August:   std::cout << "August\n"; break;
 case months::September:std::cout << "September\n"; break;
 case months::October:  std::cout << "October\n"; break;
 case months::November: std::cout << "November\n"; break;
 case months::December: std::cout << "December\n"; break;
 default: std::cout << "Wrong number !!!!!" << "\n"; continue;
             }
    }

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
