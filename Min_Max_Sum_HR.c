#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int *arr = malloc(sizeof(int) * 5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
   long long int sum[5];
   long long int total = 0;
    for(int i = 0; i < 5; i++){
        total = total + arr[i];
    }
    
    for(int j = 0 ; j<5; j++){
        sum[j] = total - arr[j];
    }
    long long int smallest = sum[0], largest = sum[0];
    for(int k = 1;k<5;k++){
            if(smallest > sum[k])
            {
                smallest = sum[k];
            }
              if(largest < sum[k]){
                largest = sum[k];
            }
        }
    
    printf("%lld %lld",smallest,largest);
    return 0;
}
