/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr_count = 5;
    int arr[arr_count];
    
    int *front;
    int *rear;
    //Initially when no values present in the array/queue then front and rear both pointing to 1st array element
    front = &(arr[0]);
    rear = &(arr[0]); 
    
    //Inputting or Enqueue values at the rear end
    printf("Enter array values:\n");
    for(int i=0;i<arr_count;i++){
        scanf("%d\n",rear);
        rear++;
    }
    rear = rear-1;
    printf("front_value = %d\n",*(front));
    printf("rear_value = %d\n",*(rear));
    
    //Deleting or Dequeue values from the front
    for(int j=0;j<arr_count;j++){
        printf("front=%d\n",*(front));
        for(int k=0;k<arr_count;k++){
            arr[k]=arr[k+1];
        }
        printf("rear=%d\n",*(rear-1));
        rear--;
    }
    front=front-1;
    printf("%d %d",*(front),*(rear));
    if(front==rear){
        printf("Queue is Empty Now!!!");
    }
    return 0;
}
