#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;


void writeFile(const string& fileName) {
    string userInput;
    ofstream file(fileName);
    if (file.is_open()) {
        // Write some sample data to the file
        file << "Sample line 1" << endl;

        cout << "Please enter your input: ";
        cin >> userInput;
        file << userInput << endl;
      
        file.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}

int main() {
    string fileName = "output.txt";

    auto start = high_resolution_clock::now();
    writeFile(fileName);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Writing to file time is: " << duration.count() << " microseconds" << endl;
    

    return 0;
}
