#include "Contractor.h"
#include "El_Paso.h"

Contractor::Contractor() {
    Name = "No Name";
}

void Contractor::setName(string Name) {
    this->Name = Name;
}
void Contractor::setHouse(House H) {
    Houses.push_back(H);
}
ostream& operator<<(std::ostream& os, Contractor& contractor) {
    int houseVal;
    os << "Contractor name: " << contractor.getName() << endl << endl;
    for (unsigned int i = 0; i < contractor.Houses.size(); i++) {
        os << "Address: " << contractor.Houses.at(i).getAddress() << endl;
        os << "Square footage: " << contractor.Houses.at(i).getSqFt() << " sf" << endl;
        //ADD to set precision of valuation to anything less than 1k get rounded up aka $500
        //os << fixed << setprecision(0);

        os << "Valuation: " << contractor.Houses.at(i).getVal() << "K" << endl << endl;
        //os << i << endl;
    }
    return os;

}
string Contractor::getName() {
    return Name;
}