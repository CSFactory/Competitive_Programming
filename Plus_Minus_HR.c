#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    float poscount = 0.0,negcount = 0.0, zerocount = 0.0;
    for(int i = 0; i < n; i++){
        if(arr[i]>0){
            poscount++;
        }
        if(arr[i]<0){
            negcount++;
        }
        if(arr[i]==0){
            zerocount++;
        }
    }
    printf("%f \n",(poscount/n));
   printf("%f \n",(negcount/n));
    printf("%f \n",(zerocount/n));
    return 0;
}
