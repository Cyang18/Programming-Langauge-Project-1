import time
import psutil
import math

def perform_math_operations():
    a = "place value here"
    b = 5
    result_addition = a + b
    result_subtraction = a - b
    result_multiplication = a * b
    result_division = a / b
    result_exponentiation = a ** b
    result_sqrt = math.sqrt(a)

    # prints to just check the results
    print("Addition:", result_addition)
    print("Subtraction:", result_subtraction)
    print("Multiplication:", result_multiplication)
    print("Division:", result_division)
    print("Exponentiation:", result_exponentiation)
    print("Square Root:", result_sqrt)

def measure_performance():

    # get the time before the function call
    start_time = time.time()

    # Function call
    perform_math_operations()

    # get the time after the function call
    end_time = time.time()
    execution_time = end_time - start_time

    # get the cpu usage
    cpu_usage = psutil.cpu_percent()

    # get memory usage
    # Memory usage in KB. Byte -> KB
    memory_usage = psutil.virtual_memory().used / 1024 

    print("\nExecution Time:", execution_time, "seconds")
    print("CPU Usage:", cpu_usage, "%")
    print("Memory Usage:", memory_usage, "KB")

if __name__ == "__main__":
    measure_performance()
