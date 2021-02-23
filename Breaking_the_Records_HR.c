#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* getRecord(int s_size, int* s, int *result_size){
    // Complete this function
    
    int highcount = 0, lowcount = 0;
    int highest = s[0];
    int lowest  = s[0];
    
    //Find Highest with highcount
    
    for(int t = 0; t< s_size; t++){
        if(highest < s[t]){
            highest = s[t];
            highcount++;
        } 
    }
    
    for(int h = 0; h < s_size; h++){
         if(lowest > s[h]){
             lowest = s[h];
             lowcount++;
        }
    }
    printf("%d %d \n",highcount,lowcount);
     
    return (0) ;
   
   
}

int main() {
    int n; 
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
       scanf("%d",&s[s_i]);
    }
    int result_size;
    int* result = getRecord(n, s, &result_size);
    for(int i = 0; i < result_size; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    puts(""); 
    return 0;
}
