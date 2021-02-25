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

// Complete the appendAndDelete function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* appendAndDelete(char* s, char* t, int k) {
char* str;
int i,j,non_matched_count=0;
int len_s=0,len_t=0,matched_count=0;
len_s = strlen(s);
len_t = strlen(t);

for(i=0,j=0;i<len_s,j<len_t;i++,j++){
    if(s[i]==t[j]){
        matched_count++;
    }
    else{
        break;
    }
}

    non_matched_count = abs(len_s+len_t-(2*matched_count));

if((non_matched_count>k)){
    str = "No";
}
else if(((abs(len_s+len_t)-2*matched_count)%2==k%2)){
    str = "Yes";
}
else if((len_s+len_t-k)<0){
    str = "Yes";
}
else{
    str = "No";
}
return str;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* t = readline();

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = appendAndDelete(s, t, k);

    fprintf(fptr, "%s\n", result);

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
