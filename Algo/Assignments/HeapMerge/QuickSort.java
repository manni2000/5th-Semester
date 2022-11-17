import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class QuickSort {
    public static void main(String[] args) {
        try {
            File quickFile = new File("quicksort.txt");
            quickFile.createNewFile(); 

            FileWriter fw = new FileWriter(quickFile.getAbsolutePath());
            
            Random rand = new Random();
            for (int inputSize = 10; inputSize <= 1000000; inputSize *= 10) {
                double avgTime = 0;
                for (int i = 0; i < 10; i++) 
                {
                    int[] arr = new int[inputSize];
                    for (int idx = 0; idx < inputSize; idx++) {
                        arr[idx] = rand.nextInt();
                    }
                    long start = System.currentTimeMillis();
                    quickSort(arr, 0, inputSize - 1);
                    long end = System.currentTimeMillis();

                    avgTime += end - start;
                    System.out.println("Iteration - " + i + " " + inputSize);

                }

                avgTime /= 10; 
                String toWrite = inputSize + " " + avgTime + "\n";
                fw.write(toWrite);
                System.out.println("Over! " + inputSize);
            }
            fw.close();

        } catch (IOException e) {
        	System.out.println("Error thrown!!!");
            e.printStackTrace();
        }
    }

    public static void quickSort(int arr[], int startIdx, int endIdx) {
        
        int midIdx;
        if (startIdx < endIdx) {
            midIdx = partition(arr, startIdx, endIdx);
            quickSort(arr, startIdx, midIdx - 1);
            quickSort(arr, midIdx + 1, endIdx);
        }
    }

    private static int partition(int arr[], int startIdx, int endIdx) {
        
        int temp1, temp2, i, j;
        temp1 = arr[endIdx];
        i = startIdx - 1;
        for (j = startIdx; j < endIdx; j++) {
            if (arr[j] <= temp1) {
                i++;
                temp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp2;
            }
        }

        temp2 = arr[i + 1];
        arr[i + 1] = arr[endIdx];
        arr[endIdx] = temp2;
        return (i + 1);
    }
}