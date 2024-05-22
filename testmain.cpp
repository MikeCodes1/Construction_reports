/*

#include <iostream>
#include "Temple.h"

int main(){
    Temple test;
    char c;
    bool test1 = false;
    ifstream inFile;
    inFile.open("Temple.txt");
    do {
        cin >> c;
        if (!inFile) {
            cerr << "ERROR" << endl;
        }
        try {
            test.ReadFile(inFile, c);
            test1 = true;
        }
        catch (BADINDEX) {
            cout << "Error wrong input try again" << endl;
        }
    }while(!test1);

    return 0;
}
*/
