#include <stdio.h>
#include <limits.h> //used for INT_MIN

int main()
{
    //Maximum Sum SubArray  - Kadane's Algorithm
    int arr_count = 5;
    int arr[5]= {-2, -3, -1, -4, -6}; //All negative values
    //int arr[6]= {2, -1, 2, 3, 4, -5};
    int maxsumsubarray = INT_MIN; //INT_MIN is used so that kadane's algo can work with all negative-valued array.
    int currentsum = 0;
    for(int i=0;i<arr_count;i++){
        currentsum = currentsum + arr[i];
        if(currentsum>maxsumsubarray){
            maxsumsubarray=currentsum;
        }
        if(currentsum<0){
            currentsum=0;
        }
    } 
    printf("maximum sum subarray %d\n",maxsumsubarray);
    
 return 0; 
}
