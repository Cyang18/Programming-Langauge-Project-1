#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

void insertionSort(vector<int>& arr, int size)

{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int temp = i-1;
        while (temp >= 0 && arr[temp] > current)
        {
            arr[temp+1] = arr[temp];
            temp--;
        }
        arr[temp+1] = current;
    }
}

int main()
{

    vector<int> array;
    int size;
    cout<<"Enter a size: ";
    cin>>size;
    for(int i=0; i < size; i++)
    {
        array.push_back(rand() % 100);
        array.push_back(array[i]);
    }
    auto start = high_resolution_clock::now();
    insertionSort(array,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion sort time is: " << duration.count() << " microseconds" << endl;

    //prints the list to make sure the algorithm sorts the list properly
    for (int j = 0; j < size; j++)
    {
        cout << ' ' << array[j];

    }

    cout << endl;
    return 0;
}
