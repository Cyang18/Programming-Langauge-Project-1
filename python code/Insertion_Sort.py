import psutil
import random
import time
#import resource

def insertion_sort(arr):
    for i in range(1, len(arr)):
        current = arr[i]
        temp = i - 1
        while temp >= 0 and arr[temp] > current:
            arr[temp + 1] = arr[temp]
            temp -= 1
        arr[temp + 1] = current

if __name__ == "__main__":
    size = int(input("Enter a size: "))
    array = ["place array values here"]

    start = time.time()
    # function call
    insertion_sort(array)
    stop = time.time()

    # Get cpu usuage
    cpu_usage = psutil.cpu_percent()

    # Get memory usage
    memory_usage = psutil.virtual_memory().used / 1024 
    
    # print the statements for exe, cpu, and mem
    print("Insertion sort time is:", (stop - start) * 1e6, "microseconds")
    print("CPU time used:", cpu_usage, "%")
    print("Memory usage:", memory_usage, "KB")

    # prints the list to make sure the algorithm sorts the list properly
    print("Sorted array:", array)
