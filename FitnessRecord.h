#ifndef FITNESS_RECORD_H
#define FITNESS_RECORD_H

#include <string>
using namespace std;

class FitnessRecord {
public:
    string location;
    string activity;
    double caloriesBurned;

    FitnessRecord(string loc, string act, double cal)
        : location(loc), activity(act), caloriesBurned(cal) {}
};

#endif // FITNESS_RECORD_H
