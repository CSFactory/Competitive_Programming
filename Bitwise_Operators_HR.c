#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int i,j,l=0;
  int and[1000000],or[1000000],xor[1000000];
  int max_and=0, max_or=0,max_xor=0;
  for(i=1;i<n;i++){
      for(j=i+1;j<=n;j++){
          and[l]= (i&j);
         // printf("and %d\n",and[l]);
          or[l]= (i|j);
         // printf("or %d\n",or[l]);
          xor[l]= (i^j);
         // printf("xor %d\n",xor[l]);
          l++;
      }
  }
  
  int m,t,x;
  int temp_and=0;
  int temp_or=0;
  int temp_xor=0;
  //Sort the arrays
  //xor sorted array
  for (int y=0;y<l;y++){
      for(int e = y+1;e<l;e++){
        if(xor[y]<xor[e]){
            temp_xor = xor[y];
            xor[y] = xor[e];
            xor[e] = temp_xor;
        }
      }
  }
  //or sorted array
    for (int y=0;y<l;y++){
      for(int e = y+1;e<l;e++){
        if(or[y]<or[e]){
            temp_or = or[y];
            or[y] = or[e];
            or[e] = temp_or;
        }
      }
  }
  //and sorted array
  for (int y=0;y<l;y++){
      for(int e = y+1;e<l;e++){
        if(and[y]<and[e]){
            temp_and = and[y];
            and[y] = and[e];
            and[e] = temp_and;
        }
      }
  }
  //max_xor
  for(int u = 0;u<l;u++){
     // printf("xor after %d\n",xor[u]);
       if(xor[u]<k){
          max_xor = xor[u];
          break;
      } 
  } 
  //max_or
    for(int u = 0;u<l;u++){
     // printf("xor after %d\n",xor[u]);
       if(or[u]<k){
          max_or = or[u];
          break;
      } 
  } 
  //max_and
  for(int u = 0;u<l;u++){
     // printf("xor after %d\n",xor[u]);
       if(and[u]<k){
          max_and = and[u];
          break;
      } 
  }
  printf("%d\n%d\n%d",max_and,max_or,max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


//EFFICIENT IMPLEMENTATION BELOW (NEITHER NEED OF SORTING NOR ADDITIONAL ARRAYS)

void calculate_the_maximum(int n, int k) {
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (((i&j) > maxAnd) && ((i&j) < k)) {
                maxAnd = i&j;
            }
            if (((i|j) > maxOr) && ((i|j) < k)) {
                maxOr = i|j;
            }
            if (((i^j) > maxXor) && ((i^j) < k)) {
                maxXor = i^j;
            }
        }
    }

    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}
