#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* timeConversion(char* s) {
    // Complete this function
    if((s[8]=='P')  && !(s[0]=='1' && s[1]=='2') ){
        s[0] = s[0]+1;
        s[1] = s[1]+2; 
        s[8] = '\0';
    }
    
       if((s[8]=='P') && (s[0]=='1') && (s[1]=='2')){
        s[8] = '\0';
    }
    
   if((s[8]=='A') && !(s[0]=='1' && s[1]=='2')){
        s[8] = '\0';
    }
    
    if((s[8]=='A') && (s[0]=='1') && (s[1]=='2')){
         s[0] = '0';
        s[1] = '0'; 
        s[8] = '\0';
    }
    
    return s;
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
   // printf("%c\n",s[8]);
        int result_size;
char* result = timeConversion(s);
    printf("%s\n", result);
    return 0;
}
