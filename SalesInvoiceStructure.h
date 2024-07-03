#ifndef SALESINVOICESTRUCTURE_H
#define SALESINVOICESTRUCTURE_H

#include "SalesInvoice.h"
#include <iostream>
#include <string>

using namespace std;

struct SalesInvoiceStructure {
    string date, invoiceCode, description;
    SalesInvoiceStructure* next;

    SalesInvoiceStructure(const string& d, const string& ic, const string& desc)
        : date(d), invoiceCode(ic), description(desc), next(NULL) {}
};

#endif

