import random
import time
import resource

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
    array = [random.randint(0, 99) for _ in range(size)]

    start = time.time()
    cpu_start = resource.getrusage(resource.RUSAGE_SELF).ru_utime + resource.getrusage(resource.RUSAGE_SELF).ru_stime
    insertion_sort(array)
    stop = time.time()
    cpu_stop = resource.getrusage(resource.RUSAGE_SELF).ru_utime + resource.getrusage(resource.RUSAGE_SELF).ru_stime

    print("Insertion sort time is:", (stop - start) * 10**6, "microseconds")
    print("CPU time used:", (cpu_stop - cpu_start), "seconds")
    print("Memory usage:", resource.getrusage(resource.RUSAGE_SELF).ru_maxrss, "KB")

    # prints the list to make sure the algorithm sorts the list properly
    print("Sorted array:", array)
