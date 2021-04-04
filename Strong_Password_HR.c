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

// Complete the minimumNumber function below.
int minimumNumber(int n, char* password) {
    // Return the minimum number of characters to make the password strong
    int ncps=0;
    int len_s=strlen(password);

        for(int i=0;i<len_s;i++){
            //check for atleast one digit
            if((password[i]>='0') && (password[i]<='9')){
                break;
            }
            else{
                if(i==len_s-1){
                ncps += 1;
                break;
                }
               
            }
        }
            //Lowercase chars check (atleast one)
        for(int j=0;j<len_s;j++){
            if((password[j]>=65) && (password[j]<=90)){
                break;
            }
            else{
                if(j==len_s-1){
               // printf("hi\n");
                ncps += 1;
                break;  
                }
               
            }
        }
            //uppercase chars check (atleast one)
        for(int u=0;u<len_s;u++){
            if((password[u]>=97) && (password[u]<=122)){
                break;
            }
            else{
                if(u==len_s-1){
                ncps += 1;
                break;
                } 
            }
        }
        
        //special char check
        for(int sp=0;sp<len_s;sp++){
            if((password[sp]==33) || (password[sp]==64) || (password[sp]==35) || (password[sp]==36) || (password[sp]==37) || (password[sp]==94) || (password[sp]==38) || (password[sp]==42) || (password[sp]==43) || (password[sp]==40) || (password[sp]==41) || (password[sp]==45)){
                break;
            }
            else{
                if(sp==len_s-1){
                ncps += 1;
                break;
                }   
            }
        }
        //Length atleast 6 check and its comparison with suggested ncps append
    if(((6-len_s)>0) && (ncps <= (6-len_s))){
        ncps = (6-len_s);
    }
return ncps;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* password = readline();

    int answer = minimumNumber(n, password);

    fprintf(fptr, "%d\n", answer);

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

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
