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

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
long int kaprekar[q];
int count=0;
long int i,j,sq_num=0,div_len=0,div_num=0,first_half=0,sec_half=0,k=0;
char str[100];
if((p!=q) && (q!=0)){
    //square the number
    for(i=p;i<=q;i++){
        sq_num = (i*i);
        //sq_num to str
        sprintf(str, "%ld", sq_num); 
       // printf("i=%d, sq_num=%d\n",i,sq_num);
        //str = sq_num;
        int len = strlen(str);
       // printf("len=%d\n",len);
        if((len%2)==0){
            div_len = len/2;
        }
        else if((len%2)!=0){
            div_len = (len+1)/2;
        }
       // printf("div_len=%d\n",div_len);
        div_num = pow(10,div_len);
       // printf("div_num = %d\n",div_num);
        sec_half = sq_num%div_num;
       // printf("sec_half=%d\n",sec_half);
        first_half = sq_num/div_num;
       // printf("first_half=%d\n",first_half);
        if((i==(first_half+sec_half))){
            kaprekar[k]=i;
            k++;
            count++;
        }
    }   
}
int yy;
if(count!=0){
    for(yy=0;yy<count;yy++){
    printf("%ld ",kaprekar[yy]);
    }
}
else{
    printf("INVALID RANGE");
}

}

int main()
{
    char* p_endptr;
    char* p_str = readline();
    int p = strtol(p_str, &p_endptr, 10);

    if (p_endptr == p_str || *p_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    kaprekarNumbers(p, q);

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
