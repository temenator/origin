// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale.h>
void sort_array(int** a,int b){
    int** sort = a;
    int size = b;
    bool flag = true;// start sort
    while (flag)
    {
        flag = false;
        for (int r = size - 1; r > 0; r--)// start iteration
        {
            int a, b;
            sort[1][r] < sort[1][r - 1] ? flag = true, a = sort[0][r], b = sort[1][r],
                sort[0][r] = sort[0][r - 1], sort[1][r] = sort[1][r - 1],
                sort[0][r - 1] = a, sort[1][r - 1] = b : sort[0][r];// crazy ternary "flag up, array r copy to "copy" change array r-1 on array r and paste copy to array r-1"
        }//end iteration

    }// end cicle
}
void  delete_two_dim_array(int** a, int rows, int cols)// delete pptr use a pptr and size
{
    int** array = a;
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    return;
}
int** create_two_dim_array(int rows, int cols)// create array of pointer
{
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols]();
    }
    return array;
}
class Address
{
private:
    std::string city;
    std::string street;
    int home;
    int apt;
    public:
    Address() {
        this->city = "none"; this->street = "none";
        this->home = 0; this->apt = 0;
    }
    Address(std::string a, std::string b, int c, int d)
    {
        this->city = a; this->street = b;
        this->home = c; this->apt = d;
    }
    std::string get_address()
    {
        return city + "\n" + street + "\n" + std::to_string(home) + "\n"
            + std::to_string(apt) + "\n";
    }
    std::string get_address_for_out()
    {
        return city + ", " + street + ", " + std::to_string(home) + ", "
            + std::to_string(apt) + "\n";
    }
    char get_address_char() { return this->city[0]; }

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
    std::cout << "\n";
    int size = 0;
    in >> size;
    std::cout << size << "\n";
    Address** array = new Address * [4];
    int** sort = create_two_dim_array(2, size);
    for (int i = 0; i < size; i++)
    {
        std::string a, b;
        int c, d;
        in >> a;
        in >> b;
        in >> c;
        in >> d;
        array[i] = new Address(a, b, c, d);
        sort[0][i] = i;
        sort[1][i] = array[i]->get_address_char();
        std::cout << array[i]->get_address();
    }
    in.close();
    std::cout << "\n";

    sort_array(sort,size);


    std::fstream out;
    out.open("out.txt", std::ios::out);
    out << size << "\n";
    std::cout << size << "\n";
    for (int i = 0; i < size; i++) {
        out << array[sort[0][i]]->get_address_for_out();
        std::cout << array[sort[0][i]]->get_address_for_out();
    }
       
    delete_two_dim_array(sort, 2, size);
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
