#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    //INPUTS
    int n,m;
    scanf("%d %d\n",&n,&m); //n=no:of_arr_elements //m=no:of_queries
    int *arr;
    arr=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]); //inputting the values
    }
    
    int queries[m][3]; //queries 2-d array
    //inputting the queries
    for(int r=0;r<m;r++){
            scanf("\n%d %d %d",&(queries[r][0]),&(queries[r][1]),&(queries[r][2]));
    }
    
    //PROCESSING
    for(int y=0;y<m;y++){
        int query_type = (queries[y][0]);
        int starting_index = (queries[y][1]);
        int end_index = (queries[y][2]);
        int temp_arr[((end_index-starting_index)+1)];
        int temp_index=0;
        //Copying the values from starting_index-1 to end_index-1 into temp array
        for(int t=(starting_index-1);t<end_index;t++){
            temp_arr[temp_index] = arr[t];
            temp_index++;
        }
       // temp_index = temp_index-1;
        
        //Process the main array for front transformation
        if(query_type==1){
            for(int cp=(starting_index-2);cp>=0;cp--){
                arr[end_index-1]=arr[cp];
                end_index--;
            }  
            for(int tr=0;tr<temp_index;tr++){
                arr[tr] = temp_arr[tr];
            }
        }  
    }
    
    for(int ll=0;ll<n;ll++){
        printf("%d ",arr[ll]);
    }
    return 0;
}
