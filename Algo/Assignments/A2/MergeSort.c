#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[] , int left , int right)
{
    int mid=(left+right)/2;
    int i=left , j=mid+1 , k=left; 
    int tmp[100000];
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
            tmp[k++]=arr[i++];
        else
            tmp[k++]=arr[j++];
    }
    while(i<=mid)
        tmp[k++]=arr[i++];
    while(j<=right)
        tmp[k++]=arr[j++];

    for(int i=left; i<=right; i++)
        arr[i]=tmp[i-left]; // transfering all temporary arr to original arr.
}

void mergeSort(int arr[] , int left , int right)
{
    if(left>=right)
        return;

    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,right);
}

void printArray(int arr[], int size){
  for(int i=0;i<size;i++){
    print("Array will be\n", arr[i]);
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
            mergeSort(arr, 0,inputSize-1);
            end = clock();

            tot+=((double)(end - start));
            
        }
        tim[k++] = tot/10;
    }

    int ip=10;
    printf("Time taken for Merge Sort - \n\n");
    for(int i=0; i<5; i++){
        printf("Average Time taken for input size - %d = %lf\n",ip,tim[i]);
        ip*=10;
    }
    printArray(arr,5);

    return 0;
}