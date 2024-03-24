import java.util.ArrayList;
import java.util.Random;

public class QuickSort {

    // Function to measure CPU time
    static double getCPUTime() {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        long start = System.nanoTime();
        return (double) start / 1e9;
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

        ArrayList<Integer> array = new ArrayList<>(Arrays.asList("put the values here"));

        double cpu_start = getCPUTime();
        long start = System.currentTimeMillis();

        // Function call
        quickSort(array, 0, size - 1);

        long stop = System.currentTimeMillis();
        double cpu_stop = getCPUTime();

        // Print statements for the execution time, CPU time, and memory
        System.out.println("Quick sort time is: " + (stop - start) + " milliseconds");
        System.out.println("CPU time used: " + ((cpu_stop - cpu_start) * 1e6) + " microseconds");
        System.out.println("Memory usage: " + getMemoryUsage() + " KB");

        // Print the sorted array to verify
        for (int j = 0; j < size; j++) {
            System.out.print(" " + array.get(j));
        }
        System.out.println();
    }
}
