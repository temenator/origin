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
    std::string get_address_city() { return this->city; }

};

void sort_array(int* sort, Address* array, int size) {
    //int* sort = a;
    //Address* array = b;
    //int size = c;

    bool flag = true;// start sort
    while (flag)
    {
        flag = false;

        for (int r = size - 1; r > 0; r--)// start iteration
        {

            int a = 0;
            array[sort[r]].get_address_city().compare(array[sort[r - 1]].get_address_city()) < 0 ? flag = true,
                a = sort[r],
                sort[r] = sort[r - 1],
                sort[r - 1] = a : sort[r];//"flag up, array r copy to "copy" change array r-1 on array r and paste copy to array r-1"
        }//end iteration

    }// end cicle
}

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
    Address* array = new Address  [size];
    int* sort = new int [size];
    for (int i = 0; i < size; i++)
    {
        std::string a, b;
        int c, d;
        in >> a;
        in >> b;
        in >> c;
        in >> d;
        array[i] =  Address(a, b, c, d);
        sort[i] = i;
       
        std::cout << array[i].get_address();
    }
    in.close();
    std::cout << "\n";

    sort_array(sort,array,size);
   
    

    std::fstream out;
    out.open("out.txt", std::ios::out);
    out << size << "\n";
    std::cout << size << "\n";
    for (int i = 0; i < size; i++) {
        out << array[sort[i]].get_address_for_out();
        std::cout << array[sort[i]].get_address_for_out();
    }
    out.close();
    delete[] array,sort;  
    array, sort = nullptr;
    
    return 0;
}
