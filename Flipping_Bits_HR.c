#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the flippingBits function below.
long flippingBits(long n) {
long converted_num = 0;

int i;
int arr[32];
for(i=31;i>-1;i--){
    arr[i] = (n%2);
    n=n/2;
}
 //test
int k,l,m;

/* for(l=0;l<32;l++){
    printf("%d",arr[l]);
}
printf("\n"); */

for(k=0;k<32;k++){
    if(arr[k]==0){
        arr[k]=1;
    }
    else if(arr[k]==1){
        arr[k]=0;
    }
}
/*for(l=0;l<32;l++){
    printf("%d",arr[l]);
}
printf("\n"); */
int x=0;
for(m=31;m>-1;m--){
   // printf("converted num = %li, arr[m] = %d , x = %d \n",converted_num,arr[m],x);
    converted_num = converted_num + ((arr[m])*(pow(2,x)));
    x++;
}
//printf("post converted num = %li",converted_num);
return (converted_num);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* n_endptr;
        char* n_str = readline();
        long n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        long result = flippingBits(n);

        fprintf(fptr, "%ld\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
