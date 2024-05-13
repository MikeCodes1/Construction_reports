#include "House.h"

House::House() {
    Address = "No Address";
    Valuation = 0000;
    SquareFt = 0000;
}
void House::setAddress(string Address) {
    this->Address = Address;
}
void House::setVal(double Val) {
    Valuation = Val;
}
void House::setSqFt(double SqFt) {
    SquareFt = SqFt;
}
string House::getAddress() {
    return Address;
}
double House::getVal() {
    return Valuation;
}
double House::getSqFt() {
    return SquareFt;
}