#ifndef TEMPLE_H_INCLUDED
#define TEMPLE_H_INCLUDED

#include "Contractor.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Temple {

private:
    vector<Contractor> cNames;
public:


    void setReadFile(ofstream& m);
    void ReadFile(ifstream& m, char c);

    void Display(ostream& m);

    int linearSearch(string key);


};

#endif // TEMPLE_H_INCLUDED