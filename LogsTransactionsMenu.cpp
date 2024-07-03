#include "LogsTransactions.h"
#include "LogsTransactionsStructure.h"

#include <iostream>
#include <string>

using namespace std;

void LogsTransactionsMenu(int& choice) {
    LogsTransactions logs;

    do {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "Logs of Transactions                                 " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Log Transaction                        " << endl;
        cout << "        [2] - Transaction History                    " << endl;
        cout << "        [3] - Search Transaction                     " << endl;
        cout << "        [4] - Delete Transaction                     " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter Transaction Description: ";
                getline(cin, description);
                logs.logTransaction(description);
                system("cls");
                break;
            }
            case 2:
                logs.displayTransactions();
                system("pause");
                break;
            case 3: {
                int id;
                cout << "Enter transaction ID to search: ";
                cin >> id;
                cin.ignore();
                logs.searchTransaction(id);
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                int id;
                cout << "Enter transaction ID to delete: ";
                cin >> id;
                cin.ignore();
                logs.deleteTransaction(id);
                system("cls");
                break;
            }
            case 5:
                cout << "Returning to Main Menu..." << endl;
                system("cls");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
                system("cls");
        }
    } while (choice != 5);
}

LogsTransactions::LogsTransactions() : head(NULL), nextId(1) {}

LogsTransactions::~LogsTransactions() {
    while (head != NULL) {
        LogsTransactionsStructure* temp = head;
        head = head->next;
        delete temp;
    }
}

void LogsTransactions::logTransaction(const string& description) {
    LogsTransactionsStructure* newLog = new LogsTransactionsStructure{nextId++, description, head};
    head = newLog;
}

void LogsTransactions::displayTransactions() const {
    LogsTransactionsStructure* current = head;
    while (current != NULL) {
        cout << "ID: " << current->id << " Description: " << current->description << endl;
        current = current->next;
    }
}

bool LogsTransactions::searchTransaction(int id) const {
    LogsTransactionsStructure* current = head;
    while (current != NULL) {
        if (current->id == id) {
            cout << "Found: ID: " << current->id << " Description: " << current->description << endl;
            return true;
        }
        current = current->next;
    }
    cout << "Transaction ID " << id << " not found." << endl;
    return false;
}

bool LogsTransactions::deleteTransaction(int id) {
    LogsTransactionsStructure* current = head;
    LogsTransactionsStructure* prev = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Transaction ID " << id << " deleted." << endl;
            return true;
        }
        prev = current;
        current = current->next;
    }
    cout << "Transaction ID " << id << " not found." << endl;
    return false;
}

