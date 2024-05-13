#include "College_Station.h"


void CollegeStation::setReadFile(ofstream& m) {
    string line;
    do {
        getline(cin, line);
        if (line != "EXIT") {
            m << line << endl;
        }
    } while (line != "EXIT");
}

void CollegeStation::ReadFile(ifstream& m) { //IDEA Make a vector of Vectors so i can store rows and collumns then have the program
    // read collumn blank for the certain type of work and then give the row this could also
    // be implemented on temple because of same excel sheet format

    //IDEA This works but temple is bell county which has commercial if you want commercial i noticed that
    //All of the FY-##-## stuff has an acryonym for things for example single family residence is SFR
    //I could create a while loop that reads the characters of only the FY line and see if the certain
    //acryonym matches for SFR or BDNC for commercial stuff
    string line, house, col, waste;
    vector<vector<string>> c;
    getline(m, waste);
    getline(m, waste);
    getline(m, waste);
    getline(m, col);
    while (m >> line) {
        if (line == "RESIDENTIAL") {
            m >> line;
            //cout << line << endl;
            if (line == "SINGLE") {
                m >> line;
                cout << line << endl;
                if (line == "FAMILY") {
                    getline(m,house);
                    cout << col << endl;
                    cout << house;
                }
            }

        }
    }
    // Prompt the user to press Enter to exit
    //cout << "Press Enter to exit...";
    //cin.ignore(); // This will wait for the user to press Enter
}