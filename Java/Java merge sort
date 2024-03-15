class Mergesort {
    static long startTime = System.nanoTime();


    void merge(int array[], int o, int p, int r){

        int x = p - o + 1;
        int y = r - p;
        int L[] =  new int[x];
        int R[] = new int[y];

        for (int i = 0; i < x; ++i){
            L[i] = array[o + i];
        }
            

        for(int j = 0; j < y; j++){
            R[j] = array[p + 1 + j];

        }
        int i = 0;
        int j = 0;

        int k = o;
        while(i < x && j < y){
            if(L[i] <= R[j]){
                array[k] = L[i];
                i++;
            }
            else{
                array[k] = R[j];
                j++;

            }
            k++;
            
        }
        while (i < x){
            array[k] = L[i];
            i++;
            k++;

        }
        while (j < y){
            array[k] = R[j];
            j++;
            k++;
        }

        

    }

    void sort(int array[], int z, int w){

        if (z < w){

            int m = (z + w) / 2;

            sort(array, z, m);
            sort(array, m + 1, w);

            merge(array, z, m, w);

        }
    }

    static void printArray(int array[]){
        int n = array.length;

        for(int i = 0; i < n; ++i){
            System.out.print(array[i] + " ");


        }
        System.out.println();


    }

    public static void main(String args[]){
        int array[] = {3,5,9,1,6,3,4,2};
        System.out.println("Given Array");
        printArray(array);

        Mergesort t = new Mergesort();
        t.sort(array, 0,array.length - 1);
        
        printArray(array);

        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println(duration);
        

    }

    
}
