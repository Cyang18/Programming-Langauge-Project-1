import random
import time
import resource

def get_cpu_time():
    return time.process_time()

def get_memory_usage():
    return resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

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

if __name__ == "__main__":
    array = []
    size = int(input("Enter a size: "))
    for i in range(size):
        array.append(random.randint(0, 99))

    start = time.time()
    cpu_start = get_cpu_time()

    quick_sort(array, 0, size - 1)

    cpu_stop = get_cpu_time()
    stop = time.time()

    duration = (stop - start) * 1e6

    print("Quick sort time is:", duration, "microseconds")
    print("CPU time used:", (cpu_stop - cpu_start) * 1e6, "microseconds")
    print("Memory usage:", get_memory_usage(), "KB")

    print("Sorted array:")
    print(array)
