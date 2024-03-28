#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


using namespace std;
using namespace std::chrono;


void readFile(const string& fileName)
{
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl; // Print each line of the file
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}

int main() {
    string fileName = "output.txt";
   
    
    auto start = high_resolution_clock::now();
    readFile(fileName);
    auto stop = high_resolution_clock::now();
     
    auto duration = duration_cast<microseconds>(stop - start);

    // prints the statements out
    cout << "Insertion sort time is: " << duration.count() << " microseconds" << endl;

    return 0;
}

