#include <iostream>
#include <vector>
#include <chrono>
#include <sys/types.h>
#include <sys/sysctl.h>

using namespace std::chrono;
using namespace std;

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

void insertionSort(std::vector<int>& arr, int size) {
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

int main() 
{
    // get random sample size
    vector<int> array;
    int size;
    cout << "Enter a size: ";
    cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        array.push_back(rand() % 100);
        array.push_back(array[i]);
    }

    // Getting the time of competition for the execution, CPU, and memory usage
    auto start = high_resolution_clock::now();
   
    insertionSort(array, size);
    auto stop = high_resolution_clock::now();
  
    auto duration = duration_cast<microseconds>(stop - start);

    // prints the statements out
    cout << "Insertion sort time is: " << duration.count() << " microseconds" << endl;
    cout << "CPU usage: " << getCPUUsage() * 100 << "%" << endl; // CPU usage in percentage
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // prints the list to make sure the algorithm sorts the list properly
    for (int j = 0; j < size; j++) {
        cout << ' ' << array[j];
    }

    cout << endl;
    return 0;
}
