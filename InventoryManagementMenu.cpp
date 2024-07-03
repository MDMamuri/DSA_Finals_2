#include "InventoryManagementClass.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 


using namespace std;

void InventoryManagementMenu(int& choice){
	system("cls");
	InventoryManagement inventory;


    do {
        system("cls");  
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Inventory Management System         " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "    Inventory Management                            " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Product                            " << endl;
        cout << "        [2] - Show Product List                      " << endl;
        cout << "        [3] - Update Product List                    " << endl;
        cout << "        [4] - Update Specific Product                " << endl;
        cout << "        [5] - Exit                                    " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.showProductList();
                break;
            case 3:
                inventory.updateProductList();
                break;
            case 4:
                inventory.updateSpecificProduct();
                break;
            case 5:
                cout << "Exiting the system..." << endl;
                system("cls");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

}










