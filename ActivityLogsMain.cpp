#include "ActivityLogsClass.h"
#include <iostream>
#include <string>

using namespace std;

void ActivityLogMenu(int& choice) {
    ActivityLog log;
    string activity;
    do {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "Activity Log                                         " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Activity                           " << endl;
        cout << "        [2] - Activity History                       " << endl;
        cout << "        [3] - Search Activity                        " << endl;
        cout << "        [4] - Delete Activity                        " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter Activity: ";
                getline(cin, activity);
                log.addActivity(activity); // Updated to call with only one argument
                system("pause");
                break;
            case 2:
                log.displayActivities();
                system("pause");
                break;
            case 3:
                cout << "Enter activity to search: ";
                getline(cin, activity);
                log.searchActivity(activity);
                system("pause");
                break;
            case 4:
                cout << "Enter activity to delete: ";
                getline(cin, activity);
                log.deleteActivity(activity);
                system("pause");
                break;
            case 5:
                cout << "Returning to Main Menu..." << endl;
                system("pause");
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                system("pause");
        }
    } while (choice != 5);
}
