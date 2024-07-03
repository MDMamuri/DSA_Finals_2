#ifndef LOGSTRANSACTIONS_H
#define LOGSTRANSACTIONS_H

#include "LogsTransactionsStructure.h"
#include <string>

class LogsTransactions {
public:
    LogsTransactions();
    ~LogsTransactions();

    void logTransaction(const string& description); 
    void displayTransactions() const; 
    bool searchTransaction(int id) const; 
    bool deleteTransaction(int id); 

private:
    LogsTransactionsStructure* head;
    int nextId;
};

#endif

