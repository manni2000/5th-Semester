#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y, z;
};

void findMaximalPoints(Point points[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (i != j and points[i].x <= points[j].x and points[i].y <= points[j].y and points[i].z <= points[j].z)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << points[i].x << "," << points[i].y << "," << points[i].z << " is a Maximal point " << endl;
    }
    cout << "************" << endl;
}

int main()
{

    float tim[5];
    int k = 0;

    for (int inputSize = 100; inputSize <= 1000; inputSize *= 10)
    {
        // Generate "inputSize" random x-points
        int arrX[inputSize], arrY[inputSize], arrZ[inputSize];
        for (int i = 0; i < inputSize; i++)
            arrX[i] = rand() % inputSize + 1;

        // Generate "inputSize" random y-points
        for (int i = 0; i < inputSize; i++)
            arrY[i] = rand() % inputSize + 1;
        
        // Generate "inputSize" random z-points
        for (int i = 0; i < inputSize; i++)
            arrZ[i] = rand() % inputSize + 1;

        Point points[inputSize];
        for (int i = 0; i < inputSize; i++)
            points[i].x = arrX[i], points[i].y = arrY[i], points[i].z = arrZ[i] ;

        // Perform 10 iterations for every inputSize
        float tot = 0.0;
        for (int i = 0; i < 10; i++)
        {
            clock_t start, end;

            start = clock();
          findMaximalPoints(points, inputSize);
            end = clock();

            tot += ((double)(end - start));
        }
        cout << "--------------Iteration for inputsize = " << inputSize << " done ---------------" << endl
             << endl;
        tim[k++] = tot / 10;
    }
}