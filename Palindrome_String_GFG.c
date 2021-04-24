//https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <string.h>


 // } Driver Code Ends
//User function Template for C

int isPlaindrome(char S[])
{
    int len = strlen(S);
    int counter=0;
    int output=0;
    // Your code goes here
    //Two pointer approach
    for(int i=0,j=len-1;i<len/2,j>=len/2;i++,j--){
        if(S[i]==S[j]){
           
            counter++;
        }
        else{
            break;
        }
    }
   
    if((((counter*2)==len) && ((len%2)==0)) || ((((counter*2)-1)==len) && ((len%2)!=0))){
        output = 1;
    }
    else{
        output = 0;
    }
    return output;
}

// { Driver Code Starts.

int main() 
{
   	int t;
   	scanf("%d", &t);
   	while(t--)
   	{
   		char s[100000];
   		scanf("%s", &s);;


   		printf("%d\n", isPlaindrome(s));
   	}

    return 0;
}  // } Driver Code Ends
