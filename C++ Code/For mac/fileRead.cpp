#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <sys/types.h>
#include <sys/sysctl.h>

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
    cout << "CPU usage: " << getCPUUsage() * 100 << "%" << endl; // CPU usage in percentage
    cout << "Memory usage: " << getMemoryUsage()/1024 << " KB" << endl;

    
    return 0;
}
