#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int birthdayCakeCandles(int n, int ar_size, int* ar) {
    // Complete this function
    int count  = 0, max = ar[0];
    
    //find max
    
    for(int i = 0; i<n; i++){
        if(max<ar[i]){
            max = ar[i];
        }
    }
    
    //find maxcount
    for(int k=0;k<n;k++){
        if(max==ar[k]){
            count++;
        }
    }
    
    return count;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = birthdayCakeCandles(n, n, ar);
    printf("%d\n", result);
    return 0;
}
