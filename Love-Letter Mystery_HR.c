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

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(char* s) {
int opr=0;
int len_s = strlen(s);
//Two Pointer approach
for(int i=0,j=len_s-1;i<=(len_s/2),j>=(len_s/2);i++,j--){
    if((s[i]!=s[j]) && (s[i]>s[j])){
        while(s[i]!=s[j]){
            s[i] = (s[i]-1);
            opr++;
        }
    }
    else if((s[i]!=s[j]) && (s[i]<s[j])){
        while(s[i]!=s[j]){
            s[j] = (s[j]-1);
            opr++;
        }
    }
}
return opr;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* s = readline();

        int result = theLoveLetterMystery(s);

        fprintf(fptr, "%d\n", result);
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
