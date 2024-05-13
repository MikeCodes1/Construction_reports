#ifndef EL_PASO_H_INCLUDED
#define EL_PASO_H_INCLUDED

#include "Contractor.h"
#include "House.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
const bool DEBUG = false;

class El_Paso {

private:
    vector<Contractor> cNames;

public:

    void setReadFile(ofstream& m);
    void ReadFile(ifstream& m);

    void ReadContractor(ifstream& m, Contractor& C);
    void ReadAddress(ifstream& m, House& H);
    void ReadValuation(ifstream& m, House& H);
    void ReadSquareFootage(ifstream& m, House& H);

    void Display(ostream& m);

    int linearSearch(string key);
};

#endif // EL_PASO_H_INCLUDED