#include "Temple.h"


void Temple::setReadFile(ofstream& m) {
    string line;
    do {
        getline(cin, line);
        if (line != "EXIT") {
            m << line << endl;
        }
    } while (line != "EXIT");
}

void Temple::ReadFile(ifstream& m, char c) { //IDEA This works but temple is bell county which has commercial if you want commercial i noticed that
    //All of the FY-##-## stuff has an acryonym for things for example single family residence is SFR
    //I could create a while loop that reads the characters of only the FY line and see if the certain
    //acryonym matches for SFR or BDNC for commercial stuff

    int commaNum = 0, Index;
    double val = 0, sqft = 0;
    Contractor* builder = new Contractor;
    House h;
    string permitID, permitType, waste, name, address, owner, temp;
    if(c == 'R' || c == 'r'){
        while(!m.eof()){
            if(commaNum == 23){ // break case aka reaches end of line
                Index = linearSearch(builder->getName());
                if (Index == -1) {
                    builder->setHouse(h);
                    cNames.emplace_back(builder);
                }
                else {
                    cNames.at(Index).setHouse(h);
                }
                delete builder;
                builder = new Contractor;
                commaNum = 0;
            }
            else if(commaNum == 0){
                getline(m,permitID,',');

            }
            else if(commaNum == 1){
                getline(m,permitType,',');
                if(!(permitType == "Res Single Family Residence" || permitType == "Res Duplex" || permitType == "Residential Attached Townhome")){
                    getline(m,waste,'\n');
                    commaNum = -1;
                }
            }
            else if(commaNum == 6){
                temp.clear();
                getline(m,temp,',');
                if(!temp.empty()){
                    val = stoi(temp);
                }
                h.setVal(val);
            }
            else if(commaNum == 7){
                temp.clear();
                getline(m,temp,',');
                if(!temp.empty()){
                    sqft = stoi(temp);
                }
                h.setSqFt(sqft);
            }
            else if(commaNum == 11){
                getline(m, name, ',');
                builder->setName(name);
            }
            else if(commaNum == 15){
                getline(m,owner,',');
                if(name.empty()){
                    builder->setName(owner);
                }
                else{
                    builder->setOwner(owner);
                }

            }
            else if(commaNum == 16){
                getline(m,address,',');
                h.setAddress(address);
            }
            else {
                getline(m, waste, ',');
            }
            commaNum++;
        }
    }
    else if(c == 'C' || c == 'c'){

    }
    else{
        throw BADINDEX();
    }




    //FIXME working program below
    /*string line;
    int Permit;
    bool temple1, temple2;
    cout << c << endl;
    if (c == 'R') {
        while (m >> line) {
            if (line == "Res") {
                Contractor C;
                House H;
                Permit = 0;
                temple1 = false;
                temple2 = false;
                while (m >> line && !temple2) {
                    if (line == "Temple" && temple1) {
                        temple2 = true;
                    }
                    else if (line == "Temple") {
                        temple1 = true;
                    }
                    cout << line << endl;
                }
                cout << endl;
            }
        }
    }
    else if (c == 'C') {
        while (m >> line) {
            if (line == "Comm") {
                temple1 = false;
                temple2 = false;
                while (m >> line && !temple2) {
                    if (line == "Temple" && temple1) {
                        temple2 = true;
                    }
                    else if (line == "Temple") {
                        temple1 = true;
                    }
                    cout << line << endl;
                }
                cout << endl;
            }
        }
    }
    else {
        cout << "ERROR" << endl;
    }*/





    // Prompt the user to press Enter to exit
    //cout << "Press Enter to exit...";
    //cin.ignore(); // This will wait for the user to press Enter
}

void Temple::Display(ostream &m) {
    for(int i = 0; i < cNames.size(); i++){
        m << cNames.at(i);
    }
}

int Temple::linearSearch(string key) {
    unsigned int i;
    int index = -1;

    for (i = 0; i < cNames.size(); ++i) {
        if (cNames.at(i).getName() == key) {
            index = i;
        }
    }
    return index;
}
