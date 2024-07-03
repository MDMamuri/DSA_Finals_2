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

    void saveToFile(bool append = false) {
        ofstream file;
        if (append) {
            file.open("employee_logs.txt", ios::app);
        } else {
            file.open("employee_logs.txt");
        }

        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (list<Employee>::iterator it = employeeList.begin(); it != employeeList.end(); ++it) {
            file << it->id << endl;
            file << it->name << endl;
            file << it->timeIn << endl;
            file << it->timeOut << endl;
        }

        file.close();
    }

public:
    void addEmployee() {
        int id;
        string name;
        char letterChoice;
        cout << "*************************************!Disclaimer!*****************************************" << endl;
        cout << "This will create a new file if you came from the main menu, deleting any existing file." << endl;
        cout << "Do you wish to proceed? (Y / N): " << endl;
        cout << "******************************************************************************************" << endl;
        cout << ": ";
        cin >> letterChoice;
        if (letterChoice == 'y' || letterChoice == 'Y'){
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
		} else if (letterChoice == 'n' || letterChoice == 'N'){
            // No action taken
        }
    }

    void readEmployeeLogs() {
        system("clear || cls");  // This works on both Unix and Windows
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
        ifstream checkFile("employee_logs.txt");
        if (!checkFile.is_open()) {
            cout << "No existing logs found. Please add an employee first." << endl;
            return;
        }

        checkFile.close();

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
        saveToFile(true);  // Append to the existing file
    }

    void recordTimeIn() {
        system("clear || cls");  // This works on both Unix and Windows
        int id;
        cout << "Enter Employee ID to record time in: ";
        cin >> id;

        for (list<Employee>::iterator it = employeeList.begin(); it != employeeList.end(); ++it) {
            if (it->id == id) {
                it->timeIn = getCurrentTime();
                cout << "Time In recorded as " << it->timeIn << endl;
                saveToFile(true);  // Append the updated log
                return;
            }
        }

        cout << "Employee not found!" << endl;
    }

    void recordTimeOut() {
        system("clear || cls");  // This works on both Unix and Windows
        int id;
        cout << "Enter Employee ID to record time out: ";
        cin >> id;

        for (list<Employee>::iterator it = employeeList.begin(); it != employeeList.end(); ++it) {
            if (it->id == id) {
                it->timeOut = getCurrentTime();
                cout << "Time Out recorded as " << it->timeOut << endl;
                saveToFile(true);  // Append the updated log
                return;
            }
        }

        cout << "Employee not found!" << endl;
    }
};

#endif
