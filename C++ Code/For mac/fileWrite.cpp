#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>

using namespace std;
using namespace std::chrono;


// Function to measure memory usage returns usage in kilobytes
long getMemoryUsage() {
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    return rusage.ru_maxrss;
}

// Function to measure CPU usage (macOS specific)
double getCPUUsage() {
    size_t size = sizeof(int);
    int cpuPercent;
    sysctlbyname("kern.cp_time", &cpuPercent, &size, NULL, 0);
    return cpuPercent / 100.0;
}

void writeFile(const string& fileName) {
    string userInput;
    ofstream file(fileName);
    if (file.is_open()) {

        // Write some sample data to the file
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
    cout << "CPU usage: " << getCPUUsage() * 100 << "%" << endl; // CPU usage in percentage
    cout << "Memory usage: " << getMemoryUsage()/1024 << " KB" << endl;

    return 0;
}
