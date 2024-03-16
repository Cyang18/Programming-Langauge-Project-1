import random
import time
import resource

# Function to measure CPU time
def get_cpu_time():
    return resource.getrusage(resource.RUSAGE_SELF).ru_utime

# Function to measure memory usage in kilobytes
def get_memory_usage():
    return resource.getrusage(resource.RUSAGE_SELF).ru_maxrss

# Function to merge two sorted subarrays
def merge(arr, left, mid, right):
    start_index_left = left
    start_index_right = mid + 1
    temp_element = left
    temp = [0] * len(arr)

    while start_index_left <= mid and start_index_right <= right:
        if arr[start_index_left] < arr[start_index_right]:
            temp[temp_element] = arr[start_index_left]
            start_index_left += 1
        else:
            temp[temp_element] = arr[start_index_right]
            start_index_right += 1
        temp_element += 1

    while start_index_left <= mid:
        temp[temp_element] = arr[start_index_left]
        temp_element += 1
        start_index_left += 1

    while start_index_right <= right:
        temp[temp_element] = arr[start_index_right]
        temp_element += 1
        start_index_right += 1

    for temp_element in range(left, right + 1):
        arr[temp_element] = temp[temp_element]

# Function to perform merge sort
def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

if __name__ == "__main__":
    # Get random sample size for testing
    size = int(input("Enter a size: "))
    array = [random.randint(0, 99) for _ in range(size)]

    # Getting the start time, CPU time, and memory usage
    start_time = time.time()
    cpu_start = get_cpu_time()

    # Function call
    merge_sort(array, 0, size - 1)

    # Getting the stop time, CPU time, and memory usage
    stop_time = time.time()
    cpu_stop = get_cpu_time()
    duration = (stop_time - start_time) * 1e6  # microseconds

    # Print the execution time, CPU time, and memory usage
    print("Merge sort time is: {:.2f} microseconds".format(duration))
    print("CPU time used: {:.2f} microseconds".format((cpu_stop - cpu_start) * 1e6))
    print("Memory usage: {} KB".format(get_memory_usage()))

    # Print the sorted list
    print("Sorted array:", array)
