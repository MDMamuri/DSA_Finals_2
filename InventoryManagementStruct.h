#ifndef INVENTORYMANAGEMENTSTRUCT_H
#define INVENTORYMANAGEMENTSTRUCT_H
#include "InventoryManagementClass.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 

using namespace std;
struct Product {
    int id;
    string name;
    int quantity;
    string supplier;

    Product(int i, string n, int q, string s) : id(i), name(n), quantity(q), supplier(s) {}
};

#endif
