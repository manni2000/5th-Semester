import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class HeapSort {
    public static void main(String[] args) {
        try {
            File quickFile = new File("heapsort.txt");
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
                    heapSort(arr, inputSize);
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

    public static void heapSort(int arr[], int size) {
        int i, temp;
        for (i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);

        for (i = size / 2 - 1; i >= 0; i--) {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }

    }

    private static void heapify(int[] arr, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int temp;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, size, largest);
        }
    }
}