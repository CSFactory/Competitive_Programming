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

// Complete the repeatedString function below.
long repeatedString(char* s, long n) {
    long j;
    long count_a = 0;
    long count_final_a = 0;
    long len_s = 0; //length of given string
    len_s = strlen(s);
    if((len_s == 1.0) && (s[0] == 'a')){
        count_final_a = n;
    }
 
    else if(len_s>1.0){
        //find no: of a's in given string
        for(j=0;j<len_s;j++){
            if(s[j]=='a'){
                count_a++;
            }
        }
   
     count_final_a = ((n/len_s)*count_a);
     int k;
     //Count remaining a's in remainder section of main string out of the given string
     for(k=0;k<(n%len_s);k++){
         if(s[k]=='a'){
             count_final_a++;
         }
     }
    }
    
return count_final_a;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* n_endptr;
    char* n_str = readline();
    long n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    long result = repeatedString(s, n);

    fprintf(fptr, "%li\n", result);

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
