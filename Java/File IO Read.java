import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;


public class read{
    static long startTime = System.nanoTime();
    public static void main(String[] args){
        try{
            File object = new File("output.txt");
            Scanner reader = new Scanner(object);
            while(reader.hasNextLine()){
                String data = reader.nextLine();
                //System.out.println(data);

            }
            reader.close();
            
        } catch (FileNotFoundException e){
            e.printStackTrace();
        }
        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println(duration);
    }
  
}

