#include "Contractor.h"
#include "House.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class CollegeStation {

private:
    vector<Contractor> cNames;
    bool newContractor;
public:


    void setReadFile(ofstream& m);
    void ReadFile(ifstream& m);

    void Display(ostream& m);

    int linearSearch(string key);




};
