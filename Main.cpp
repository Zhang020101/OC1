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

    cout << "输入bin文件名 Введите имя файла bin:\n";
    cin >> bin_name;
    cout << "输入记录的数量 Введите количество записей:\n";
    cin >> num;

    sprintf_s(par, "%s %s %s", "Creator.exe", bin_name, num);
    cout << "启动进程Creator.exe" << endl;

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


    cout << "\n输入报告文件的名称 Введите имя файла отчета\n";
    cin>>rep_name;

    cout << "输入工资 Введите зарплату \n";
    cin>>grade;

    sprintf_s(par, "%s %s %s %s", "Reporter.exe", bin_name, rep_name, grade);
    cout << "启动进程Reporter.exe" << endl;

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