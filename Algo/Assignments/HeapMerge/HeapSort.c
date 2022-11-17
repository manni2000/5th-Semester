#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    
    //Perform 10 iteartions for every input size
    double tim[5];
    int k=0;
    for(int inputSize=10; inputSize<=100000; inputSize*=10)
    {
        int arr[inputSize];
        double tot=0;
        for(int j=0; j<inputSize; j++)
            arr[j]=rand() % inputSize + 1;
        
        for(int i=0; i<10; i++)
        {
            clock_t start, end;
        
            start = clock();
            heapSort(arr,inputSize);
            end = clock();

            tot+=((double)(end - start));
            
        }
        tim[k++] = tot/10;
    }

    int ip=10;
    printf("Time taken for Heap Sort - \n\n");
    for(int i=0; i<5; i++){
        printf("Average Time taken for input size - %d = %lf\n",ip,tim[i]);
        ip*=10;
    }
        
    printf("\n");
    

    return 0;
}