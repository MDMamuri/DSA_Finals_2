// MANAGEEMPLOYEELOGSSTRUCT.h
#ifndef MANAGEEMPLOYEELOGSSTRUCT_H
#define MANAGEEMPLOYEELOGSSTRUCT_H
#include "ManageEmployeeLogsClass.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <ctime> 
using namespace std;

struct Employee {
    int id;
    string name;
    string timeIn;
    string timeOut;
    
    //bool File_Employee_Exist = false;

    Employee(int i, string n, string tIn, string tOut) : id(i), name(n), timeIn(tIn), timeOut(tOut) {}
};


#endif

