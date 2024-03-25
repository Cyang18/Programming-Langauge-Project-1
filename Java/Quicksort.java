import java.util.ArrayList;
import java.util.Arrays;
import java.time.Duration;
import java.time.Instant;

public class QuickSort {

    // Function to measure CPU time
    static double getCPUTime() {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long start = System.nanoTime();
        long startCpuTime = runtime.totalMemory() - runtime.freeMemory();
        return (double) (start + startCpuTime) / 1e9;
    }

    // Function to measure memory usage returns usage in kb
    static long getMemoryUsage() {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return (runtime.totalMemory() - runtime.freeMemory()) / 1024;
    }

    static void swap(ArrayList<Integer> arr, int x, int y) {
        int temp = arr.get(x);
        arr.set(x, arr.get(y));
        arr.set(y, temp);
    }

    static void quickSort(ArrayList<Integer> arr, int low, int high) {
        if (low < high) {
            int partition = partition(arr, low, high);
            quickSort(arr, low, partition - 1);
            quickSort(arr, partition + 1, high);
        }
    }

    static int partition(ArrayList<Integer> arr, int low, int high) {
        int pivot = arr.get(high);
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr.get(j) <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    public static void main(String[] args) {

        // Define your static array here
        ArrayList<Integer> array = new ArrayList<>(Arrays.asList("put the values here"));

        // Adding size declaration here similar to the older code 
        int size = array.size(); 

        Instant start = Instant.now();
        double cpu_start = getCPUTime();

        // Function call
        quickSort(array, 0, size - 1);

        Instant stop = Instant.now();
        double cpu_stop = getCPUTime();

        Duration duration = Duration.between(start, stop);

        // Print statements for the execution time, CPU time, and memory
        System.out.println("Quick sort time is: " + (duration.toNanos() / 1000) + " microseconds");
        System.out.println("CPU time used: " + ((cpu_stop - cpu_start) * 1e6) + " microseconds");
        System.out.println("Memory usage: " + getMemoryUsage() + " KB");

        // Print the sorted array to verify
        for (int j = 0; j < size; j++) {
            System.out.print(" " + array.get(j));
        }
        System.out.println();
    }
}
