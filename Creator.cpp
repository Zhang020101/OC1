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
        cout << "����Ĳ�������"<<endl;
        return 1;
    }

    const int numberOfEmployes = atoi(argv[2]);

    ofstream binFile(argv[1], ios::binary | ios::out);
    for (int i = 0; i < numberOfEmployes; i++)
    {
        employee node;
        cout << "\n����ID ���ӧ֧էڧ�� ID: ";
        cin >> node.num;

        cout << "\n�������� ���ӧ֧էڧ�� �ڧާ�: ";
        //cin.getline(node.name, 10);
        cin >> node.name;
        cout << "\nEnter amount of hours: ";
        cin >> node.hours;
        cout << "\n=============================" << endl;
        binFile.write((char*)&node, sizeof(employee));
    }

    binFile.close();
}