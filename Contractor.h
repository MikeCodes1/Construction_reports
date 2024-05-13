#ifndef CONTRACTOR_H_INCLUDED
#define CONTRACTOR_H_INCLUDED

#include <vector>
#include <iostream>
#include "House.h"

using namespace std;

class Contractor {

private:
    string Name;
    vector<House> Houses;

public:
    Contractor();

    void setName(string);
    void setHouse(House);

    friend ostream& operator<<(ostream& os, Contractor& contractor);

    string getName();



};


#endif // CONTRACTOR_H_INCLUDED