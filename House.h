#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#include <iostream>

using namespace std;

class BADINDEX{};
class House {

private:
    string Address;
    double Valuation;
    double SquareFt;

public:
    House();
    void setAddress(string);
    void setVal(double);
    void setSqFt(double);


    string getAddress();
    double getVal();
    double getSqFt();


};


#endif // HOUSE_H_INCLUDED