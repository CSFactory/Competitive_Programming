#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    //Two Pointer Approach
    int temp=0;
    for(int i=0,j=num-1;i<(num/2),j>=(num/2);i++,j--){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
