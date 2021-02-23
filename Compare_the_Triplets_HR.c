#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int simpleArraySum(int n, int ar_size, int* ar) {
    int sum = 0;
    for(int i = 0; i < (ar_size); i++)
    {
       // printf("before %d \n", sum);
        sum = sum + ar[i];
      //  printf("after %d \n", sum);
    }
    return sum;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = simpleArraySum(n, n, ar);
    printf("%d\n", result);
    return 0;
}
