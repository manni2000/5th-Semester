#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int left, int pivot)
{
    int x = arr[pivot];
    int j = left - 1;

    for (int i = left; i <= pivot - 1; i++)
    {
        if (arr[i] < x)
        {
            j = j + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], arr[pivot]);
    return j + 1;
}

void quickSort(vector<int> &arr, int left, int pivotIndex)
{
    if (left < pivotIndex)
    {
        int partitionIndex = partition(arr, left, pivotIndex);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, pivotIndex);
    }
}
int main(int argc, char const *argv[])
{

    // vector<int> arr = {2, 8, 7, 1, 3, 10, 5, 6, 4};
    // int r = arr.size() - 1;
    int n = 100;
    cout<<"\t\nQuickSort will be:\n";
    cout<<"\t N"<<"\t\tTime in seconds\n";
    while (n <= 100000)
    {
        vector<int> arr(n);
        srand(time(NULL));

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
        clock_t start, end;
        // sort(arr.begin(), arr.end());
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        // for (auto it : arr)
        //     cout << it << " ";
        // cout << endl;
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\t "<<n<<"\t\t" << fixed << time_taken << setprecision(5) << " secs\n";
        n = n * 10;
    }

    return 0;
}
