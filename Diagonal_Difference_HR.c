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
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
       }
    }
    
    int d1 = 0;
    int d2 = 0;
    
    for(int i = 0,j = 0; i < n,j < n; i++,j++ ){
         d1 = d1 + a[i][j];   
    }
     for(int p = n-1,q = 0; p>=0,q<n ; p--,q++ ){
         d2 = d2 + a[p][q];   
    }
    int result = abs(d1 - d2);
    printf("%d", result);
    return 0;
}
