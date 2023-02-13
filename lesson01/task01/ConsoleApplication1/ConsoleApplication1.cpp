// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
int main()
{
    int size_one;
    int size_two;


    std::fstream text;
    text.open("in.txt");
    if (text)
    {
        std::cout << "file open\n";
    }

    else
    {
        std::cout << "file corrupted or nothing";
        return 0;
    }
    text >> size_one;//read one
    int* array_one = new int[size_one];// new pointer for array and memory alloc
    for (int i = 0; i < size_one; i++)
    {
        text >> array_one[i];
    }
    text >> size_two;//read two
    int* array_two = new int[size_two];// new pointer for array and memory alloc
    for (int i = 0; i < size_two; i++)
    {
        text >> array_two[i];
    }
    text.close();

    int x;//left rotate
    x = array_one[0];
    for (int i = 0; i < size_one-1; i++)
    {
        array_one[i] = array_one[i + 1];
    }
    array_one[size_one - 1] = x;

    x = array_two[size_two - 1];//right rotate
    for (int i = size_two - 1; i > 0; i--)
    {
        array_two[i] = array_two[i - 1];
    }
    array_two[0] = x;


    std::ofstream out;
    out.open("out.txt", std::ios::out);
    
    out << size_two<< "\n";
       
    for (int i = 0; i < size_two; i++)
    {
        out << array_two[i] << " ";

    }
    out << "\n"<<size_one<<"\n";
    for (int i = 0; i < size_one; i++)
    {
        out << array_one[i] << " ";
    }
    out.close();
    delete[] array_one;
    delete[] array_two;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
