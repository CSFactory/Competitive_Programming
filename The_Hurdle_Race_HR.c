#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *height = malloc(sizeof(int) * n);
    for(int height_i = 0; height_i < n; height_i++){
       scanf("%d",&height[height_i]);
    }
    // your code goes here
    //Find Max
    int max_height = height[0];
    for(int i = 0; i < n; i++){
       if(max_height < height[i]){
           max_height = height[i];
       }
    }
    int solution = max_height - k;
    if(solution <= 0){
        printf("%d",0);
    }
    else{
        printf("%d",solution);
    }
    
    return 0;
}
