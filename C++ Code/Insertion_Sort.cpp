#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <ctime>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std::chrono;
using namespace std;

// Function to measure CPU time
double getCPUTime()
{
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    struct timeval utime = rusage.ru_utime;
    struct timeval stime = rusage.ru_stime;
    return (utime.tv_sec + utime.tv_usec / 1000000.0) + stime.tv_sec + stime.tv_usec / 1000000.0;
}

// Function to measure memory usage returns usage in kilobytes
long getMemoryUsage()
{
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    return rusage.ru_maxrss; 
}

void insertionSort(vector<int>& arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int temp = i - 1;
        while (temp >= 0 && arr[temp] > current)
        {
            arr[temp + 1] = arr[temp];
            temp--;
        }
        arr[temp + 1] = current;
    }
}

int main()
{

    vector<int> array;
    int size;
    cout << "Enter a size: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        array.push_back(rand() % 100);
        array.push_back(array[i]);
    }
    auto start = high_resolution_clock::now();
    double cpu_start = getCPUTime();
    insertionSort(array, size);
    auto stop = high_resolution_clock::now();
    double cpu_stop = getCPUTime();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion sort time is: " << duration.count() << " microseconds" << endl;
    cout << "CPU time used: " << ((cpu_stop - cpu_start) * 1e6) << " micoseconds" << endl;
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // prints the list to make sure the algorithm sorts the list properly
    for (int j = 0; j < size; j++)
    {
        cout << ' ' << array[j];
    }

    cout << endl;
    return 0;
}
