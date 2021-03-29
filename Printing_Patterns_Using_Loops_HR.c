#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      int outline = ((n*2)-1);
      int darray[outline][outline];
      int begin = 0;
      int end = outline-1;
    //Logic
      while(n!=0){
          for(int i=begin;i<=end;i++){
            for(int j=begin;j<=end;j++){
                if((i==begin) || (i==end) || (j==begin) || (j==end)){
                    darray[i][j] = n; 
                }
            }
        }
        --n;
        ++begin;
        --end;
    }
       
     //Printing the Array 
    for(int i=0;i<outline;i++){
          for(int j=0;j<outline;j++){
              printf("%d ",darray[i][j]);
          }
          printf("\n");
      } 
      
    return 0;
}
