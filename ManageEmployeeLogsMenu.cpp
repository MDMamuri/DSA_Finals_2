#include "ManageEmployeeLogsClass.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 
	//int ans, Y, y, N, n ;
	//bool FileSaveManageEmployeeLogs = false;


using namespace std;

void ManageEmployeeLogsMenu(int& choice){
	EmployeeLog logManager;

    do {
    	system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "    Employee Logs                                   " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Employee                           " << endl;
        cout << "        [2] - Read Employee Logs                     " << endl;
        cout << "        [3] - Update Logs                            " << endl;
        cout << "        [4] - Record Time In                         " << endl;
        cout << "        [5] - Record Time Out                        " << endl;
        cout << "        [6] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                logManager.addEmployee();
                system("pause");
                break;
            case 2:
                logManager.readEmployeeLogs();
                system("pause");
                break;
            case 3:
                logManager.updateLogs();
                system("pause");
                break;
            case 4:
                logManager.recordTimeIn();
                system("pause");
                break;
            case 5:
                logManager.recordTimeOut();
                system("pause");
                break;
            case 6:
                cout << "Returning to Main Menu..." << endl;
                system("cls");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

}
