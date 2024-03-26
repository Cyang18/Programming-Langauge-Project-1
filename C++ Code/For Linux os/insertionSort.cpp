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
    return (non_idle_time / static_cast<double>(total_time)) * 100; // CPU usage in percentage
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


void insertionSort(vector<int>& arr, int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int temp = i - 1;
        while (temp >= 0 && arr[temp] > current) {
            arr[temp + 1] = arr[temp];
            temp--;
        }
        arr[temp + 1] = current;
    }
}

int main() {
    // Get random sample size
    vector<int> array;
    int size;
    cout << "Enter a size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % 100);
    }

    // Getting the time of start for the execution
    auto start = high_resolution_clock::now();

    insertionSort(array, size);

    // Getting the time of completion for the execution
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the results
    cout << "Insertion sort time: " << duration.count() << " microseconds" << endl;
    cout << "CPU usage: " << getCPUUsage() << "%" << endl;
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // Print the sorted list
    for (int j = 0; j < size; j++) {
        cout << array[j] << ' ';
    }
    cout << endl;

    return 0;
}
