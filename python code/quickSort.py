import random
import time
import psutil


def quick_sort(arr, low, high):
    if low < high:
        partition = low - 1
        pivot = arr[high]
        for i in range(low, high):
            if arr[i] <= pivot:
                partition += 1
                arr[partition], arr[i] = arr[i], arr[partition]
        arr[partition + 1], arr[high] = arr[high], arr[partition + 1]

        quick_sort(arr, low, partition)
        quick_sort(arr, partition + 2, high)

# main
if __name__ == "__main__":

  # Get random sample size for testing
    size = int(input("Enter a size: "))
    array = [random.randint(0, 99) for _ in range(size)]

    start_time = time.time()

    # the function call
    quick_sort(array, 0, size - 1)

    stop_time = time.time()

    # changing the seconds to micoseconds
    duration = (stop_time - start_time) * 1e6  

    # Print the execution time, CPU time, and memory usage
    print("Merge sort time is:", duration, "microseconds")

    # Get cpu usuage
    cpu_usage = psutil.cpu_percent()
    print("CPU usage is:", cpu_usage, "%")

    # Get memory usage
    memory_usage = psutil.virtual_memory().used / 1024 
    print("Memory usage:", memory_usage, "KB")

    print("Sorted array:")
    print(array)
