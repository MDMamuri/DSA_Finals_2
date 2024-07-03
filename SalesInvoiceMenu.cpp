#include "SalesInvoice.h"
#include "SalesInvoiceStructure.h"
#include <iostream>
#include <string>

using namespace std;

void SalesInvoiceMenu(int&) {
    SalesInvoice salesInvoice;
    int choice;

    do {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "Sales Invoice                                        " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Invoice                            " << endl;
        cout << "        [2] - Invoice History                        " << endl;
        cout << "        [3] - Search Invoice                         " << endl;
        cout << "        [4] - Delete Invoice                         " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();
        system("cls");

        string date, invoiceCode, description;

        switch (choice) {
            case 1:
                cout << "Enter Date (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Enter Invoice Code: ";
                getline(cin, invoiceCode);
                cout << "Enter Description: ";
                getline(cin, description);
                salesInvoice.addInvoice(date, invoiceCode, description);
                break;
            case 2:
                salesInvoice.printInvoices();
                system("pause");
                break;
            case 3:
                cout << "Enter invoice code to search: ";
                getline(cin, invoiceCode);
                salesInvoice.searchInvoice(invoiceCode);
                system("pause");
                break;
            case 4:
                cout << "Enter invoice code to delete: ";
                getline(cin, invoiceCode);
                salesInvoice.deleteInvoice(invoiceCode);
                system("pause");
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

SalesInvoice::~SalesInvoice() {
    while (head) {
        SalesInvoiceStructure* temp = head;
        head = head->next;
        delete temp;
    }
}

void SalesInvoice::addInvoice(const string& date, const string& invoiceCode, const string& description) {
    SalesInvoiceStructure* newInvoice = new SalesInvoiceStructure(date, invoiceCode, description);
    newInvoice->next = head;
    head = newInvoice;
    history.push(newInvoice);
    cout << "Invoice added successfully.\n";
}

void SalesInvoice::printInvoices() const {
    SalesInvoiceStructure* current = head;
    while (current) {
        cout << "Date: " << current->date << ", Invoice Code: " << current->invoiceCode << ", Description: " << current->description << "\n";
        current = current->next;
    }
}

void SalesInvoice::printInvoiceHistory() const {
    stack<SalesInvoiceStructure*> temp = history;
    while (!temp.empty()) {
        SalesInvoiceStructure* invoice = temp.top();
        cout << "Date: " << invoice->date << ", Invoice Code: " << invoice->invoiceCode << ", Description: " << invoice->description << "\n";
        temp.pop();
    }
}

void SalesInvoice::searchInvoice(const string& invoiceCode) const {
    SalesInvoiceStructure* current = head;
    while (current) {
        if (current->invoiceCode == invoiceCode) {
            cout << "Invoice found: Date: " << current->date << ", Invoice Code: " << current->invoiceCode << ", Description: " << current->description << "\n";
            return;
        }
        current = current->next;
    }
    cout << "Invoice not found.\n";
}

void SalesInvoice::deleteInvoice(const string& invoiceCode) {
    SalesInvoiceStructure* current = head;
    SalesInvoiceStructure* prev = NULL;

    while (current && current->invoiceCode != invoiceCode) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "Invoice not found.\n";
        return;
    }

    if (!prev) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    history.push(current);
    delete current;
    cout << "Invoice deleted successfully.\n";
}


