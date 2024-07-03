#ifndef ACTIVITYLOGSSTRUCTURE_H
#define ACTIVITYLOGSSTRUCTURE_H
#include "ActivityLogsClass.h"
#include <string>

using namespace std;

struct ActivityLogStructure{
    string activity;
    string date;
    ActivityLogStructure* next;
    ActivityLogStructure(const string& act, const string& dt) : activity(act), date(dt), next(NULL) {}
};

#endif
