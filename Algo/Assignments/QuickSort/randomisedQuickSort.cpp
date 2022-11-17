#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

// generate a random index in between the range
int generateRandom(int lower, int upper)
{
    srand(time(NULL));
    int num = (rand() % (upper - lower + 1)) + lower;

    return num;
}

// partition function
int partition(vector<int> &arr, int left, int pivotIndex)
{
    int pivotElement = arr[pivotIndex];
    int j = left - 1;

    for (int i = left; i <= pivotIndex-1; i++)
    {
        if (arr[i] < pivotElement)
        {
            j = j + 1;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[j + 1], arr[pivotIndex]);
    return j + 1;
}

int randomized_partition(vector<int> &arr, int left, int pivotIndex)
{
    int i = generateRandom(left, pivotIndex);
    swap(arr[left], arr[i]);

    return partition(arr, left, pivotIndex);
}

void randomizedQuicksort(vector<int> &arr, int left, int pivotIndex)
{
    if (left < pivotIndex)
    {
        int q = randomized_partition(arr, left, pivotIndex);
        randomizedQuicksort(arr, left, q - 1);
        randomizedQuicksort(arr, q + 1, pivotIndex);
    }
}

int main(int argc, char const *argv[])
{

    int n = 100;
    cout<<"\t\n randomizedQuicksort will be:\n";
    cout<<"\t N"<<"\t\t Time in seconds\n";
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
        randomizedQuicksort(arr, 0, n - 1);
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