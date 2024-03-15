#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std::chrono;
using namespace std;

double getCPUTime()
{
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    struct timeval utime = rusage.ru_utime;
    struct timeval stime = rusage.ru_stime;
    return utime.tv_sec + utime.tv_usec / 1000000.0 + stime.tv_sec + stime.tv_usec / 1000000.0;
}

long getMemoryUsage()
{
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    return rusage.ru_maxrss;
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
    quickSort(array, 0, size - 1);
    double cpu_stop = getCPUTime();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Quick sort time is: " << duration.count() << " microseconds" << endl;
    cout << "CPU time used: " << (cpu_stop - cpu_start) << " seconds" << endl;
    cout << "Memory usage: " << getMemoryUsage() << " KB" << endl;

    // prints the list to make sure the algorithm sorts the list properly
    for (int j = 0; j < size; j++)
    {
        cout << ' ' << array[j];
    }

    cout << endl;
    return 0;
}

