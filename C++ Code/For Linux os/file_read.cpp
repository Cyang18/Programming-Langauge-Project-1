#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <unistd.h> 

using namespace std::chrono;
using namespace std;

// Function to measure CPU usage
double getCPUUsage() 
{
    ifstream file("/proc/stat");
    string line;
    getline(file, line);
    istringstream iss(line);
    string cpu;
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
    int idle_time = idle + iowait;
    int non_idle_time = user + nice + system + irq + softirq + steal;
    int total_time = idle_time + non_idle_time;
    return ((non_idle_time / static_cast<double>(total_time)) * 100); 
}

long getMemoryUsage() 
{
    ifstream file("/proc/self/status");
    string line;
    long memoryUsageKB = 0;
    while (getline(file, line)) 
    {
        istringstream iss(line);
        string key;
        if (iss >> key) 
        {
            if (key == "VmRSS:") 
            { 
                long value;
                if (iss >> value) 
                {
                    memoryUsageKB = value;
                    break; 
                }
            }
        }
    }
    return memoryUsageKB;
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

  cout << "sort time: " << duration.count() << " microseconds" << endl;
  cout << "CPU usage: " << getCPUUsage() << "%" << endl;
  cout << "Memory usage: " << getMemoryUsage()/1024 << " KB" << endl;

    return 0;
}
