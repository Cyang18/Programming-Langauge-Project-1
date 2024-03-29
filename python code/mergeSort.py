import random
import time
import psutil

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

    # Function call
    merge_sort(array, 0, size - 1)

    # Getting the stop time, CPU time, and memory usage
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

    # Print the sorted list
    print("Sorted array:", array)
