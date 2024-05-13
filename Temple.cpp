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
    string line;
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
    }
    // Prompt the user to press Enter to exit
    //cout << "Press Enter to exit...";
    //cin.ignore(); // This will wait for the user to press Enter
}