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
   
// insertionSort(array, size);
    mergeSort(array, 0, size - 1);
    auto stop = high_resolution_clock::now();
  
    auto duration = duration_cast<microseconds>(stop - start);

    // prints the statements out
    cout << "Merge sort time is: " << duration.count() << " microseconds" << endl;
    cout << "CPU usage: " << getCPUUsage() * 100 << "%" << endl; // CPU usage in percentage
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // prints the list to make sure the algorithm sorts the list properly
    for (int j = 0; j < size; j++) {
        cout << ' ' << array[j];
    }

    cout << endl;
    return 0;
}

