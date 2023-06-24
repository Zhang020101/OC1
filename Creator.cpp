#include <iostream>
#include <fstream>
using namespace std;

struct employee {
    int num;
    char name[10];
    double hours;
};

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "错误的参数数量"<<endl;
        return 1;
    }

    const int numberOfEmployes = atoi(argv[2]);

    ofstream binFile(argv[1], ios::binary | ios::out);
    for (int i = 0; i < numberOfEmployes; i++)
    {
        employee node;
        cout << "\n输入ID Введите ID: ";
        cin >> node.num;

        cout << "\n输入姓名 Введите имя: ";
        //cin.getline(node.name, 10);
        cin >> node.name;
        cout << "\nEnter amount of hours: ";
        cin >> node.hours;
        cout << "\n=============================" << endl;
        binFile.write((char*)&node, sizeof(employee));
    }

    binFile.close();
}