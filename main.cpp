/* Instruction
    Hotel Management System

    - HR Staff Management: Manages All Employed, Applicants
    - Stock Management: Manages stocks of possible ingredients(Cafe, Restaurant, Bar, etc.), materials for rooms, cleaning tools, pool materials, gardening materials
    - Sales Invoice: in Cafe, Room Accommodation, Restaurant Reservation, etc.
    - Report Making: Audit Logs, Reports of Failures, Logs of Transactions in inventory, Activity Log,
    - Client Data Management: Repeated Clients, Type of Clients
*/

#include "ManageEmployeeLogsClass.h"
#include "ActivityLogsClass.h"
#include "InventoryManagementClass.h"
#include "LogsTransactions.h"
#include "SalesInvoice.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 

using namespace std;

void ManageEmployeeLogsMenu(int&);
void InventoryManagementMenu(int&);
void LogsTransactionsMenu(int&);
void ActivityLogMenu(int&);
void SalesInvoiceMenu(int&);

int main(){
	system("cls");
    int choice;
    do {
        cout << "=====================================================" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "     [1] - Manage Employee Logs                      " << endl;
        cout << "     [2] - Inventory Management                      " << endl;
        cout << "     [3] - Logs of Transactions                      " << endl;
        cout << "     [4] - Activity Log                              " << endl;
        cout << "     [5] - Sales Invoice                             " << endl;
        cout << "     [0] - Exit                                      " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << ": ";
        cin >> choice;

        switch (choice) {
            case 1:
                ManageEmployeeLogsMenu(choice);
                break;
            case 2:
                InventoryManagementMenu(choice);
                break;
            case 3:
                LogsTransactionsMenu(choice);
                break;
            case 4:
                ActivityLogMenu(choice);
                break;
            case 5:
                SalesInvoiceMenu(choice);
                break;
            case 0:
                system("cls");
                cout << "Exiting!!" << endl;
                break;
            default:
                cout << "Invalid Choice. Please Try Again!!" << endl;
                system("pause");
                system("cls");
                break;
        }
    } while (choice != 0);

    cout << "Thank you so much!!" << endl;
    return 0;
}


