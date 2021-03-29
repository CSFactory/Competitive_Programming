#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int freq(char *s,int num){
    int counter=0;
    int length = strlen(s);
    for(int i=0;i<length;i++){
        if(num==(s[i]-'0')){
            counter++;
        }
    }
    return counter;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char s[1000];
    int arr[10],count=0;
    scanf("%s",s);
    for(int i=0;i<10;i++){
        arr[i] = freq(s,i);
    }
    for(int j=0;j<10;j++){
        printf("%d ",arr[j]);
    }  
    return 0;
}
