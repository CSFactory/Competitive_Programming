#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d){
    int max=0;
    int arr[4]={a,b,c,d};
    int i,j;
    for(i=1;i<4;i++){
        if(arr[0] < arr[i]){
            arr[0] = arr[i];
        } 
    }
    max = arr[0];
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
