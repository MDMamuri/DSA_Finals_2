#ifndef ACTIVITYLOGSCLASS_H
#define ACTIVITYLOGSCLASS_H
#include "ActivityLogsStructure.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>




class ActivityLog{
public:
    ActivityLog() : head(NULL) {
        loadFromFile();
    }

    ~ActivityLog() {
        saveToFile();
        while (head) {
            ActivityLogStructure* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void addActivity(const string& activity) {
        string date = getCurrentTime();
        ActivityLogStructure* newActivity = new ActivityLogStructure(activity, date);
        newActivity->next = head;
        head = newActivity;
        cout << "Activity added: " << activity << " on " << date << endl;
    }

    void displayActivities() const {
        ActivityLogStructure* current = head;
        while (current) {
            cout << current->activity << " on " << current->date << endl;
            current = current->next;
        }
    }

    void searchActivity(const string& activity) const {
        ActivityLogStructure* current = head;
        bool found = false;
        while (current) {
            if (current->activity == activity) {
                cout << "Activity found: " << activity << " on " << current->date << endl;
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Activity not found: " << activity << endl;
        }
    }

    void deleteActivity(const string& activity) {
        if (!head) {
            cout << "No activities to delete." << endl;
            return;
        }

        if (head->activity == activity) {
            ActivityLogStructure* temp = head;
            head = head->next;
            delete temp;
            cout << "Activity deleted: " << activity << endl;
            return;
        }

        ActivityLogStructure* current = head;
        while (current->next && current->next->activity != activity) {
            current = current->next;
        }

        if (current->next) {
            ActivityLogStructure* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Activity deleted: " << activity << endl;
        } else {
            cout << "Activity not found: " << activity << endl;
        }
    }

private:
    ActivityLogStructure* head;

    string getCurrentTime() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

    void saveToFile() const {
        ofstream file("activity_log.txt");
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        ActivityLogStructure* current = head;
        while (current) {
            file << current->activity << endl;
            file << current->date << endl;
            current = current->next;
        }

        file.close();
    }

    void loadFromFile() {
        ifstream file("activity_log.txt");
        if (!file.is_open()) {
            return;
        }

        string activity, date;
        while (getline(file, activity) && getline(file, date)) {
            ActivityLogStructure* newActivity = new ActivityLogStructure(activity, date);
            newActivity->next = head;
            head = newActivity;
        }

        file.close();
    }
};

#endif
