#include <iostream>
#include <fstream>
#include "Temple.h"
#include "El_Paso.h"
#include "College_Station.h"

using namespace std;


int main()
{
    //Data Abstraction
    string fileName, NameOfProgram, TypeOfFile, reRun;
    vector<string> c;
    ifstream inFile;
    ofstream outFile;
    El_Paso EL_PASO;
    Temple Temple;
    CollegeStation CollegeStation;
    bool ERROR1, ERROR2, RERUN, RVC = false;
    char c1;
    //Input
    do {
        RERUN = false;
        cout << "Are you Inputting a file or Extracting a file: ";
        cin >> TypeOfFile;
        ERROR1 = false;
        if (TypeOfFile == "Inputting") {
            do {
                ERROR2 = false;
                cout << "What City are you Inputting for?" << endl;
                cout << "LIST:   El Paso, Temple, College Station" << endl;
                cin.ignore();
                getline(cin, NameOfProgram);
                cout << endl;

                if (NameOfProgram == "El Paso") {
                    cout << "Inputting El Paso File" << endl << "Type EXIT to stop reading the information" << endl;
                    outFile.open("El_Paso.txt");
                    EL_PASO.setReadFile(outFile);
                    outFile.close();
                }

                else if (NameOfProgram == "Temple") {
                    cout << "Inputting Temple File" << endl << "Type EXIT to stop reading the information" << endl;
                    outFile.open("Temple.txt");
                    Temple.setReadFile(outFile);
                    outFile.close();
                }
                else if (NameOfProgram == "College Station"){
                    cout << "Inputting College Station File" << endl << "Type EXIT to stop reading the information" << endl;
                    outFile.open("College Station.txt");
                    CollegeStation.setReadFile(outFile);
                    outFile.close();
                }
                else {
                    ERROR2 = true;
                    cout << "ERROR wrong city name please enter again" << endl;
                }
            } while (ERROR2);
        }
        else if (TypeOfFile == "Extracting") {
            do {
                ERROR2 = false;
                cout << "Choose from list of what reports you are doing " << endl;
                cout << "LIST:  El Paso, Temple, Bryan, College Station, Bell, Coryell, and McLennan" << endl;
                cin.ignore(); //This is the problem with the loop i realized that for some reason it is chopping off the first char of the NameOfProgram
                // String which is causing the if statements to be wrong
                getline(cin, NameOfProgram);
                cout << NameOfProgram << endl;
                //cout << endl;
                if (NameOfProgram == "El Paso") {
                    //The way to do this is dowload El Paso PDF and then convert it to a .txt in zamzar then copy and paste into program.
                    cout << "Reading El Paso File" << endl << endl;
                    inFile.open("El_Paso.txt");
                    EL_PASO.ReadFile(inFile);
                    inFile.close();
                    EL_PASO.Display(cout);
                }
                else if (NameOfProgram == "Temple") {
                    //This program go to the Temple website and dowload as a hmtml or something like that which pops up as a google edge page then copy and paste
                    //from that and it should be in a vertical format
                    cout << "Residential type R or Commercial type C. ";
                    cout << "Reading Temple File" << endl << endl;
                    inFile.open("Temple.txt");
                    do {
                        cin >> c1;
                        if(!inFile){
                            cerr << "ERROR not in file" << endl;
                        }
                        try {
                            Temple.ReadFile(inFile, c1);
                            RVC = true;
                        }
                        catch (BADINDEX) {
                            cout << "Error wrong input try again" << endl;
                        }
                    }while(!RVC);
                    inFile.close();
                    Temple.Display(cout);
                }
                else if (NameOfProgram == "College Station") {
                    cout << "Reading College Station File" << endl << endl;
                    inFile.open("College Station.txt");
                    CollegeStation.ReadFile(inFile);
                    inFile.close();
                }
                else {
                    cout << "ERROR wrong city name please enter again" << endl;
                    ERROR2 = true;
                }


            } while (ERROR2);
        }
        else {
            cout << "ERROR wrong input please enter again" << endl;
            ERROR1 = true;
        }
        cout << "Program executed successfully!" << endl;
        if (!ERROR1) {
            cout << "Do you want to run again? type YES or NO" << endl;
            cin >> reRun;
            if (reRun == "YES" || reRun == "yes") {
                RERUN = true;
            }
            else if (reRun == "NO" || reRun == "no") {
                RERUN = false;
            }
        }
    } while (ERROR1 || RERUN);

    // Prompt the user to press Enter to exit
    cout << "Press Enter to exit...";
    cin.ignore(); // This will wait for the user to press Enter

    return 0;
}