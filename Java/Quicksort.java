import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.time.Duration;
import java.time.Instant;
import java.util.*;
public class QuickSort {


    // Function to measure memory usage returns usage in kb
    static long getMemoryUsage() {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return (runtime.totalMemory() - runtime.freeMemory());/ 1024;
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

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a size: ");
        int size = scanner.nextInt();


        // Define your static array here
        ArrayList<Integer> array = new ArrayList<>(Arrays.asList());

        // Adding size declaration here similar to the older code 

        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            array.add(rand.nextInt(100));


        }
        long start = System.nanoTime();



        // Function call
        QuickSort t = new QuickSort();
        t.quickSort(array, 0, size - 1);

        long stop = System.nanoTime();
        long duration = stop - start;


      

        // Print statements for the execution time, CPU time, and memory
        System.out.println("Quick sort time is: " + (duration / 1000) + " microseconds");
        
        System.out.println("Memory usage: " + getMemoryUsage() + " KB");

        // Print the sorted array to verify
        for (int j = 0; j < size; j++) {
            System.out.print(" " + array.get(j));
        }
        System.out.println();
    }
}
