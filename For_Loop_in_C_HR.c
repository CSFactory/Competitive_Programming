#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b,c;
    scanf("%d\n%d", &a, &b);
    c=a;
      // Complete the code.
    for(int i=a;i<=b;i++){
        if(a==1){
            printf("one\n");
        }
        else if(a==2){
            printf("two\n");
        }
        else if(a==3){
            printf("three\n");
        }
        else if(a==4){
            printf("four\n");
        }
        else if(a==5){
            printf("five\n");
        }
        else if(a==6){
            printf("six\n");
        }
        else if(a==7){
            printf("seven\n");
        }
        else if(a==8){
            printf("eight\n");
        }
        else if(a==9){
            printf("nine\n");
            break;
        }
        a++;
    }
    
    for(int j=c;j<=b;j++){
        if(j>9){
          if(j%2==0){
            printf("even\n");
        }
        else{
            printf("odd\n");
        }  
        c++;
        }
    }
    return 0;
}

