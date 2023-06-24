#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

const int len_num = 4;
const int len_name = 20;
const int len_par = 50;

struct employee {
    int num;
    char name[10];
    double hours;
};

void print(char* file_name, bool bin)
{
    cout << "\n\n" << file_name << ":\n";
    ifstream fin;

    if (bin)
    {
        fin.open(file_name, ios::binary | ios::out);
        employee temp;
        do
        {
            fin.read((char*)&temp, sizeof(employee));
            cout << temp.num << " " << temp.name << " " << temp.hours << endl;
        } while (fin.gcount() > 0);
    }
    else
    {
        fin.open(file_name);
        while (!fin.eof())
        {
            string tmp;
            getline(fin, tmp);
            cout << tmp << endl;
        }
    }


    fin.close();

    cout << "\n\n";
}

int main()
{
    char bin_name[len_name];
    char num[len_num];
    char par[len_par];
    char rep_name[len_name];
    char grade[len_num];

    cout << "����bin�ļ��� ���ӧ֧էڧ�� �ڧާ� ��ѧۧݧ� bin:\n";
    cin >> bin_name;
    cout << "�����¼������ ���ӧ֧էڧ�� �ܧ�ݧڧ�֧��ӧ� �٧ѧ�ڧ�֧�:\n";
    cin >> num;

    sprintf_s(par, "%s %s %s", "Creator.exe", bin_name, num);
    cout << "��������Creator.exe" << endl;

    STARTUPINFOA sinf;
    ZeroMemory(&sinf, sizeof(STARTUPINFO));
    sinf.cb = sizeof(STARTUPINFO);

    PROCESS_INFORMATION pi;
    CreateProcessA(NULL, par, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sinf, &pi);
    //DWORD exit_code;
    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    print(bin_name, true);


    cout << "\n���뱨���ļ������� ���ӧ֧էڧ�� �ڧާ� ��ѧۧݧ� ����֧��\n";
    cin>>rep_name;

    cout << "���빤�� ���ӧ֧էڧ�� �٧ѧ��ݧѧ�� \n";
    cin>>grade;

    sprintf_s(par, "%s %s %s %s", "Reporter.exe", bin_name, rep_name, grade);
    cout << "��������Reporter.exe" << endl;

    STARTUPINFOA si;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    PROCESS_INFORMATION piApp;
    CreateProcessA(NULL, par, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);
    //DWORD exit_code_1;
    WaitForSingleObject(piApp.hProcess, INFINITE);

    CloseHandle(piApp.hThread);
    CloseHandle(piApp.hProcess);

    print(rep_name, false);
}