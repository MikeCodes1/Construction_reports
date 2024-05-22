#ifndef CONTRACTOR_H_INCLUDED
#define CONTRACTOR_H_INCLUDED

#include <vector>
#include <iostream>
#include "House.h"

using namespace std;

class Contractor {

private:
    string Name;
    string owner;
    vector<House> Houses;

public:
    Contractor();

    void setOwner(string);
    void setName(string);
    void setHouse(House);

    friend ostream& operator<<(ostream& os, Contractor& contractor);

    string getOwner();
    string getName();


    Contractor(Contractor *pContractor);
};


#endif // CONTRACTOR_H_INCLUDED