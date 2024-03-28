import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;


public class read{

    static long startTime = System.nanoTime();

    // Function to measure memory usage returns usage in kb
    static long getMemoryUsage()
    {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return (runtime.totalMemory() - runtime.freeMemory());
    }

    // Function to read file
    static void readFile(String fileName)
    {
        try {
            File file = new File(fileName);
            Scanner reader = new Scanner(file);

            while (reader.hasNextLine()) {
                String data = reader.nextLine();
                System.out.println(data);

            }
            reader.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String fileName = "output.txt";

        long start = System.nanoTime();
        readFile(fileName);
        long stop = System.nanoTime();

        long duration = stop - start;


        System.out.println("Insertion sort time is: " + (duration / 1000) + " microseconds");
        System.out.println("Memory usage: " + getMemoryUsage() + " KB");

    }
}

