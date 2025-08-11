#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 5;
int array1[MAX] = {10, 20, 30, 40, 50};
int array2[MAX];

const string filename = "output.dat";

int main() {
    // Writing data to the file
    ofstream ofile;
    ofile.open(filename, ios::trunc | ios::binary);

    if (!ofile) {
        cerr << "Error opening file for writing!" << endl;
        return 1; // Return with error code
    }

    // Write the array to the file
    ofile.write((char*)&array1, sizeof(array1));

    if (!ofile) {
        cerr << "Error writing to file!" << endl;
        ofile.close();
        return 1; // Return with error code
    }

    ofile.close();

    // Reading data from the file
    ifstream ifile;
    ifile.open(filename, ios::binary);

    if (!ifile) {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Return with error code
    }

    // Read the data into array2
    ifile.read((char*)&array2, sizeof(array2));

    if (!ifile) {
        cerr << "Error reading from file!" << endl;
        ifile.close();
        return 1; // Return with error code
    }

    ifile.close();

    // Display the contents of array2
    for (int i = 0; i < MAX; i++) {
        cout << array2[i] << endl;
    }

    return 0;
}

