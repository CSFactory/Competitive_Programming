/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int fact = 0;
int facto(int n){
    
    if(n==0 || n==1){
        return 1;
    }
    else{
        fact  = n*facto(n-1); 
    }
    return fact;
}

int number_of_trailing_zeroes(int n){
    int res = 0;
    for(int i=5;i<=n;i=i*5){
        res = res + n/i;
    }
    return res;
}

int main()
{
    int final_fact = 0;
    int n = 25;
    final_fact = facto(n);
    printf("%d %d",final_fact,number_of_trailing_zeroes(n));
    return 0;
}
