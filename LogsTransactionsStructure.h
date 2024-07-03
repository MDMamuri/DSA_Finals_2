#ifndef LOGSTRANSACTIONSSTRUCTURE_H
#define LOGSTRANSACTIONSSTRUCTURE_H

#include <string>

using namespace std;

struct LogsTransactionsStructure {
    int id;
    string description;
    LogsTransactionsStructure* next;
};

#endif

