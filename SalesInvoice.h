#ifndef SALESINVOICE_H
#define SALESINVOICE_H

#include "SalesInvoiceStructure.h"
#include <iostream>
#include <string>
#include <stack>


class SalesInvoice
{
private:
    SalesInvoiceStructure* head;
    stack<SalesInvoiceStructure*> history;

public:
    SalesInvoice() : head(NULL) {}
    string date, invoiceCode, description;
    ~SalesInvoice();

    void addInvoice(const string& date, const string& invoiceCode, const string& description);
    void printInvoices() const;
    void printInvoiceHistory() const;
    void searchInvoice(const string& invoiceCode) const;
    void deleteInvoice(const string& invoiceCode);
};


#endif

