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

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partition = 0;
        int pivot = arr[high];
        int temp = (low - 1);
        for (int i = low; i <= high - 1; i++)
        {
            if (arr[i] <= pivot)
            {
                temp++;
                swap(arr[temp], arr[i]);
            }
        }
        swap(arr[temp + 1], arr[high]);
        partition = (temp + 1);

        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
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

    quickSort(array, 0, size - 1);


    // Getting the time of completion for the execution
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the results
    cout << "Quick sort time: " << duration.count() << " microseconds" << endl;
    cout << "CPU usage: " << getCPUUsage() << "%" << endl;
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // Print the sorted list
    for (int j = 0; j < size; j++) {
        cout << array[j] << ' ';
    }
    cout << endl;

    return 0;
}
