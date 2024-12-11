#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string data;
    // Creating an output file
    ofstream f1("Test.txt");
    if (!f1){
        cout << "File cannot be accessed";
    }
    else{
        cout << "File created" << endl;
        
        // Writing to the file
        cout << "Writing to file\nEnter data: ";
        cin>>data;
        f1 << data << endl;
        f1.close();

        // Opening the file as an input file
        ifstream f2("Test.txt");
        if (!f2){
            cout << "Error opening file for reading";
        }
        else{
            cout << "Reading file" << endl;
            // Reading data from the file
            while (f2 >> data){
                cout << "Data = " << data << endl;
            }
            f2.close();
        }
    }
    return 0;
}