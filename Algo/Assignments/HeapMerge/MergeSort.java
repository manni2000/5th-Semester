import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class MergeSort {
    public static void main(String[] args) {
        try {
            File quickFile = new File("mergesort.txt");
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
                    mergeSort(arr, inputSize);
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

    public static void mergeSort(int[] a, int n) {
        if (n < 2)
            return;

        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];

        for (int i = 0; i < mid; i++)
            l[i] = a[i];

        for (int i = mid; i < n; i++)
            r[i - mid] = a[i];

        mergeSort(l, mid);
        mergeSort(r, n - mid);

        merge(a, l, r, mid, n - mid);
    }

    private static void merge(int[] a, int[] l, int[] r, int left, int right) {
        int i = 0, j = 0, k = 0;
        while (i < left && j < right) {
            if (l[i] <= r[j])
                a[k++] = l[i++];
            else
                a[k++] = r[j++];
        }

        while (i < left) {
            a[k++] = l[i++];
        }

        while (j < right) {
            a[k++] = r[j++];
        }
    }
}