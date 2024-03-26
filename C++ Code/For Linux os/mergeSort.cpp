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
    return ((non_idle_time / static_cast<double>(total_time)) / 100); 
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


// prototype
void merge(vector<int>& arr, int left, int mid, int right);

void merge(vector<int>& arr, int left, int mid, int right)
{
    int start_index_left = left;
    int start_index_right = mid + 1;
    int temp_element = left;
    int temp[500000];


    while (start_index_left <= mid && start_index_right <= right)
    {
        if (arr[start_index_left] < arr[start_index_right])
        {
            temp[temp_element] = arr[start_index_left];
            start_index_left++;
        }
        else {
            temp[temp_element] = arr[start_index_right];
            start_index_right++;
        }
        temp_element++;
    }


    if (start_index_left > mid)
    {
        while (start_index_right <= right)
        {
            temp[temp_element] = arr[start_index_right];
            temp_element++;
            start_index_right++;
        }
    }

    else {

        while (start_index_left <= mid)
        {
            temp[temp_element] = arr[start_index_left];
            temp_element++;
            start_index_left++;
        }
    }

    for (int temp_element = left; temp_element <= right; temp_element++)
    {
        arr[temp_element] = temp[temp_element];
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergeSort(array, 0, size - 1);


    // Getting the time of completion for the execution
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the results
    cout << "Merge sort time: " << duration.count() << " microseconds" << endl;
    cout << "CPU usage: " << getCPUUsage() << "%" << endl;
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // Print the sorted list
    for (int j = 0; j < size; j++) {
        cout << array[j] << ' ';
    }
    cout << endl;

    return 0;
}
