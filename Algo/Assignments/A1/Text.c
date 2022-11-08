
// Online C compiler to run C program online

#include <stdio.h>
#include<time.h>
double power(int x,int n)
    {
          if(n==1)
            return x;
            else
          return (power(x,n/2)*power(x,n/2));
    }
int main() {
    
    clock_t time;                                
    time = clock();
    printf("Value= %lf \n",power(2,64));
    time = clock()-time;
    double time_taken=((double)time)/CLOCKS_PER_SEC;
    printf("Time_taken =%lf micro seconds",time_taken*1000000);
}