#ifndef MANAGEEMPLOYEELOGS_H
#define MANAGEEMPLOYEELOGS_H

#include "ManageEmployeeLogsStruct.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime>

using namespace std;

class EmployeeLog {
private:
    queue<Employee> employeeQueue;
    stack<Employee> employeeStack;
    list<Employee> employeeList;

    string getCurrentTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

public:
    void addEmployee() {
        int id;
        string name;
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Employee Name: ";
            getline(cin, name);

            Employee empty(id, name, "", "");
            employeeQueue.push(empty);
            employeeList.push_back(empty);
            employeeStack.push(empty);
            cout << "Employee added successfully!" << endl;
            saveToFile(); 
    } 

    void readEmployeeLogs() {
        system("cls");
        ifstream file("employee_logs.txt");
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        int id;
        string name, timeIn, timeOut;

        while (file >> id) {
            file.ignore();
            getline(file, name);
            getline(file, timeIn);
            getline(file, timeOut);

            Employee empty(id, name, timeIn, timeOut);
            cout << "ID: " << empty.id << ", Name: " << empty.name << ", Time In: " << empty.timeIn
                 << ", Time Out: " << empty.timeOut << endl;
        }

        file.close();
    }

    void updateLogs() {
        system("cls");
        int id;
        string name;
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);

        Employee empty(id, name, "", "");
        employeeQueue.push(empty);
        employeeList.push_back(empty);
        employeeStack.push(empty);
        cout << "Employee added successfully!" << endl;
        saveToFile();
    }

    void recordTimeIn() {
        system("cls");
        int id;
        cout << "Enter Employee ID to record time in: ";
        cin >> id;

        list<Employee>::iterator it;
        for (it = employeeList.begin(); it != employeeList.end(); ++it) {
            if (it->id == id) {
                it->timeIn = getCurrentTime();
                cout << "Time In recorded as " << it->timeIn << endl;
                saveToFile();
                return;
            }
        }

        cout << "Employee not found!" << endl;
    }

    void recordTimeOut() {
        system("cls");
        int id;
        cout << "Enter Employee ID to record time out: ";
        cin >> id;

        list<Employee>::iterator it;
        for (it = employeeList.begin(); it != employeeList.end(); ++it) {
            if (it->id == id) {
                it->timeOut = getCurrentTime();
                cout << "Time Out recorded as " << it->timeOut << endl;
                saveToFile();
                return;
            }
        }

        cout << "Employee not found!" << endl;
    }

    void saveToFile() {
        ofstream file("employee_logs.txt", ios::app);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        list<Employee>::iterator it;
        for (it = employeeList.begin(); it != employeeList.end(); ++it) {
            file << it->id << endl;
            file << it->name << endl;
            file << it->timeIn << endl;
            file << it->timeOut << endl;
        }

        file.close();
    }
};

#endif

