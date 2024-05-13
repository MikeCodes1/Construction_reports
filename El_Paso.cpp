#include "El_Paso.h"

void El_Paso::setReadFile(ofstream& m){
    string line;
    do {
        getline(cin, line);
        if (line != "EXIT") {
            m << line << endl;
        }
    } while (line != "EXIT");
}

void El_Paso::ReadFile(ifstream& m) {
    string line;
    int Permit, Index;

    while (m >> line) {

        if (line == "Number:") {
            Contractor C;
            House H;
            Permit = 0;
            while (m >> line && Permit <= 4) {
                if (line == "Contractor") {
                    ReadContractor(m, C);
                    Index = linearSearch(C.getName());
                    Permit++;
                }

                else if (line == "Address:") { //ADD a sort so you can sort the address if the street name is the same
                    ReadAddress(m, H);
                    Permit++;
                }
                else if (line == "Valuation:") {
                    ReadValuation(m, H);
                    Permit++;
                }
                else if (line == "Description:") {
                    ReadSquareFootage(m, H);
                    Permit++;
                }

            }
            if (Index == -1) {
                C.setHouse(H);
                cNames.push_back(C);
            }
            else {
                cNames.at(Index).setHouse(H);
            }
        }


    }

}
void El_Paso::ReadContractor(ifstream& m, Contractor& C) {
    string line, waste, name;

    getline(m, waste);
    getline(m, name);
    if (name == "HOMEOWNER") {
        getline(m, name);
    }
    C.setName(name);

    if (DEBUG) cout << name << endl;
}
void El_Paso::ReadAddress(ifstream& m, House& H) {
    string line, address;
    getline(m, address, ',');
    H.setAddress(address);
    if (DEBUG) cout << address << endl;

}
void El_Paso::ReadValuation(ifstream& m, House& H) {
    string line, Val;
    double ValNum;
    cout << fixed << setprecision(0);
    m >> Val;
    Val.erase(remove(Val.begin(), Val.end(), '$'), Val.end());
    Val.erase(remove(Val.begin(), Val.end(), ','), Val.end());
    ValNum = stod(Val);
    H.setVal(ValNum);
    if (DEBUG) cout << "$" << ValNum << endl;
}

void El_Paso::ReadSquareFootage(ifstream& m, House& H) {
    string line, squarefootage;
    double sqft;
    stringstream ss;
    getline(m, squarefootage);
    if ((squarefootage.find('(') != string::npos && squarefootage.find(')') != string::npos) && squarefootage.find('AC') == string::npos) { //Make another case for the square feet that is not within the ()
        squarefootage = squarefootage.substr(squarefootage.find('(') + 1, squarefootage.find(')') - 5 - (squarefootage.find('(') + 1));
        ss << squarefootage;
        ss >> sqft;
        H.setSqFt(sqft);
        if (DEBUG) cout << sqft << " SQFT" << endl;
    }
    else {
        if (DEBUG) cout << "No Square Footage" << endl;
    }
}




void El_Paso::Display(ostream& m) {
    unsigned int i;

    for (i = 0; i < cNames.size(); i++) {
        m << cNames.at(i) << endl;
    }
}



int El_Paso::linearSearch(string key) {
    unsigned int i;
    int index = -1;

    for (i = 0; i < cNames.size(); ++i) {
        if (cNames.at(i).getName() == key) {
            index = i;
        }
    }
    return index;
}