import java.util.*;
import java.time.Duration;
import java.time.Instant;

public class InsertionSort {

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

    static void insertionSort(ArrayList<Integer> arr) {
        int size = arr.size();
        for (int i = 1; i < size; i++) {
            int current = arr.get(i);
            int temp = i - 1;
            while (temp >= 0 && arr.get(temp) > current) {
                arr.set(temp + 1, arr.get(temp));
                temp--;
            }
            arr.set(temp + 1, current);
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a size: ");
        int size = scanner.nextInt();

        ArrayList<Integer> array = new ArrayList<>();

        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            array.add(rand.nextInt(100));
        }

        Instant start = Instant.now();
        double cpu_start = getCPUTime();

        // function call
        insertionSort(array);
        Instant stop = Instant.now();
        double cpu_stop = getCPUTime();

        Duration duration = Duration.between(start, stop);

        // prints the statements for the exe, cpu, and mem.
        System.out.println("Insertion sort time is: " + (duration.toNanos() / 1000) + " micoseconds");
        System.out.println("CPU time used: " + ((cpu_stop - cpu_start)* 1e6) + " micoseconds");
        System.out.println("Memory usage: " + getMemoryUsage() + " KB");

        // prints the list to make sure the algorithm sorts the list properly
        for (int j = 0; j < size; j++) {
            System.out.print(" " + array.get(j));
        }

        System.out.println();
    }
}
