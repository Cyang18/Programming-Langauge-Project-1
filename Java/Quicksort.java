class quicksort{
    

    int part(int array[], int low, int high){

        int pivot = array[high];
        int i = (low - 1);

        for(int j = low; j < high; j++){
            if(array[j] <= pivot){
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }


        }
        int temp = array[i+1];
        array[i+1] = array[high];

        array[high] = temp;

        return i + 1;
    }

    void sort(int array[], int low, int high){
        if (low < high){

            int pi = part(array,low,high);

            sort(array, low, pi - 1);
            sort(array, pi + 1, high);
        }
    }
    static void printArray(int array[])
    {
        int n = array.length;
        for (int i=0; i<n; ++i)
            System.out.print(array[i]+" ");
        System.out.println();
    }

    public static void main(String args[]){
        long startTime = System.nanoTime();

        int array[] = {5,1,8,4,6,5,2};
        int n = array.length;

        quicksort x = new quicksort();

        x.sort(array, 0, n - 1);

        System.out.println("sorted array");

        printArray(array);

        long endTime = System.nanoTime();
        long duration = endTime - startTime;
        System.out.println(duration);
    }
}
