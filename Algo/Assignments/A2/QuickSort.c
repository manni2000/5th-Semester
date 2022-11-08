#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int part(int arr[] , int left , int right)
{
    int piv=arr[right];
    int i=left-1;
    for(int j=left; j<=right; j++)
    {
        if(arr[j]<piv)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}

void quickSort(int arr[] , int left , int right)
{
    if(left>right)
        return;
    int pivot=part(arr,left,right);
    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1,right);
}

int main()
{
    
    //Perform 10 iteartions for every input size
    double tim[4];
    int k=0;
    for(int inputSize=10; inputSize<=10000; inputSize*=10)
    {
        int arr[inputSize];
        double tot=0;
        for(int j=0; j<inputSize; j++)
            arr[j]=rand() % inputSize + 1;
        
        for(int i=0; i<10; i++)
        {
            clock_t start, end;
        
            start = clock();
            quickSort(arr, 0,inputSize-1);
            end = clock();

            tot+=((double)(end - start));
            
        }
        tim[k++] = tot/10;
    }

    int ip=10;
    printf("Time taken for Quick Sort - \n\n");
    for(int i=0; i<4; i++){
        printf("Average Time taken for input size - %d = %lf\n",ip,tim[i]);
        ip*=10;
    }
    
    //Scanf("%d", int &b);
    // Printf("%d",b);

    return 0;
}