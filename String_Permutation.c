

#include <stdio.h>
#include<string.h>

void swap(char *a,char *b){
    char temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

void permute(char *s,int low,int high){
    if(low==high){ //Base Condition //if only one character in the given string, print it.
        printf("%s\n",s);
    }
    else{
        for(int i=low;i<=high;i++){
            swap(s+low,s+i); //Swap-1
            permute(s,low+1,high); //Recursion
            swap(s+low,s+i); //AntiSwap to swap-1 or Backtrack
        }
    }
}

int main()
{
    char str[] = "ABCDE"; //static string
    int length = strlen(str);
    permute(str,0,length-1);
    return 0;
}
