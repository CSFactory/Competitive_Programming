#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  
    //For single charactor
    char ch;
    scanf("%c",&ch);
    printf("%c\n",ch);
    scanf("\n");
  
    //For a string
    char str[100];
    scanf("%s",&str);
    printf("%s\n",str);
    scanf("\n");
  
    //For a sentence
    char sen[100];
    scanf("%[^\n]", sen);
    printf("%s",sen);
    return 0;
    
}
