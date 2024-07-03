#ifndef INVENTORYMANAGEMENTCLASS_H
#define INVENTORYMANAGEMENTCLASS_H
#include "InventoryManagementStruct.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 



class InventoryManagement {
private:
    queue<Product> productQueue; 
    stack<Product> productStack; 
    list<Product> productList; 

    void saveToFile() {
        ofstream file("inventory_log.txt");
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (list<Product>::iterator it = productList.begin(); it != productList.end(); ++it) {
            file << it->id << endl;
            file << it->name << endl;
            file << it->quantity << endl;
            file << it->supplier << endl;
        }

        file.close();
	}

    void loadFromFile() {
        ifstream file("inventory_log.txt");
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        int id, quantity;
        string name, supplier;

        while (file >> id) {
            file.ignore();
            getline(file, name);
            file >> quantity;
            file.ignore();
            getline(file, supplier);

            Product p(id, name, quantity, supplier);
            productList.push_back(p);
        }

        file.close();
    }

public:
    InventoryManagement() {
        loadFromFile();
    }

    ~InventoryManagement() {
        saveToFile();
    }


    void addProduct() {
    	system("cls");
        bool product_exist = false;
        int id, quantity;
        char Letter_choice;
        string name, supplier;
        
        if (product_exist == false){
            cout << "*************************************!Disclaimer!*****************************************" << endl;
            cout << "This will create a new file if you came from the main menu, deleting any existing file."    <<endl;
            cout<<  "Do you wish to proceed? (Y / N): " << endl;
            cout << "******************************************************************************************" << endl;
            cout << ": ";
            cin >> Letter_choice;
               if (Letter_choice == 'y' || Letter_choice == 'Y') {
                cout << "Enter Product ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Product Name: ";
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cin.ignore();
                cout << "Enter Supplier Name: ";
                getline(cin, supplier);
    
                Product p(id, name, quantity, supplier);
                productQueue.push(p);
                productList.push_back(p);
                productStack.push(p);
    
                cout << "Product added successfully!" << endl;
                // Append the new product to the file
                ofstream file("inventory_log.txt", ios::app);
                if (!file.is_open()) {
                    cout << "Error opening file!" << endl;
                    return;
                }
    
                file << p.id << endl;
                file << p.name << endl;
                file << p.quantity << endl;
                file << p.supplier << endl;
                
                product_exist=true;
                file.close();
            } else if (Letter_choice == 'n' || Letter_choice == 'N') {
                return;
            } 
        }else if(product_exist == true){
            return ;
        }
        system("pause");
    }


    void showProductList() {
    	system("cls");
        cout << "Product List:" << endl;
        for (list<Product>::iterator it = productList.begin(); it != productList.end(); ++it) {
            cout << "ID: " << it->id << ", Name: " << it->name << ", Quantity: " << it->quantity
                 << ", Supplier: " << it->supplier << endl;
        }
    }


    void updateProductList() {
    	system("cls");
        int id, quantity;
        string name, supplier;

        cout << "Enter Product ID for the new product: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore();
        cout << "Enter Supplier Name: ";
        getline(cin, supplier);

        Product newProduct(id, name, quantity, supplier);
        productList.push_back(newProduct);


        ofstream file("inventory_log.txt", ios::app);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        file << newProduct.id << endl;
        file << newProduct.name << endl;
        file << newProduct.quantity << endl;
        file << newProduct.supplier << endl;

        file.close();

        cout << "New product added successfully!" << endl;
    }

    void updateSpecificProduct() {
    	system("cls");
        int id;
        int add, sub;
        cout << "Enter Product ID to update: ";
        cin >> id;

        for (list<Product>::iterator it = productList.begin(); it != productList.end(); ++it) {
            if (it->id == id) {
                int choice;
                cout << "-----------------------------------------------------" << endl;
                cout << "         Harley Inventory Management System         "  << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "   Update Menu:                                       "<< endl;
                cout << "                                                      "<<endl;
                cout << "       [1] - Update Name"                              << endl;
                cout << "       [2] - Add Quantity"                             << endl;
                cout << "       [3] - Subtract Quantity"                        << endl; 
                cout << "       [4] - Update Supplier"                          << endl;
                cout << "                                                      "<<endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Choose an option: ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1:
                        cout << "Enter new Name: ";
                        getline(cin, it->name);
                        break;
                    case 2:
                        cout << "Add Quantity: ";
                        cin >> add;
                        it->quantity = it->quantity + add;
                        cin.ignore();
                        break;
                    case 3:
                        cout << "Subtract Quantity: ";
                        cin >> sub;
                        it->quantity = it->quantity - sub;
                        cin.ignore();
                        break;
                    case 4:
                        cout << "Enter new Supplier Name: ";
                        getline(cin, it->supplier);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        return;
                }

                cout << "Product updated successfully!" << endl;
                saveToFile();
                return;
            }
        }

        cout << "Product not found!" << endl;
    }
};



#endif
