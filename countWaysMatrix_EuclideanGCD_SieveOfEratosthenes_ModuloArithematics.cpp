/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int sieveOfEratosthenes(int n){
    int countPrimeInRange = 0;
    
    bool isPrime[n+1];
    fill(isPrime,isPrime+n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i=2;i*i<=n;i++){
        for(int j=2*i;j<=n;j += i){
            isPrime[j] = false;
        }
    }
    
    for(int i=0;i<=n;i++){
        if(isPrime[i]==true){
            printf("Prime: %d\n",i);
            countPrimeInRange++;
        }
    }
    return countPrimeInRange;
}

int gcd(int a, int b){
    
    if (b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

static long moduloArithematics(long a,long b,int n){ //find a power b with modulo 1000000007
    
    long res = 1;
    
    while(b>0){
        if((b&1)!=0){ //means b is an odd number
            res = ((res%n * a%n) % n);
        }
        
        a = ((a%n * a%n) % n);
        b = b >> 1; //means (b=b/2)
    }
    
    return res;
}

int countWays(int a, int b){
    int count = 0;
    if(a==1 || b==1) return 1; //base case
    return countWays(a-1,b) + countWays(a,b-1);
}

int main()
{
    int n = 12;
    int a = 3;
    int b = 2;
    int countPrimeNum = 0;
   // countPrimeNum = sieveOfEratosthenes(n);
    //printf("%d \n",countPrimeNum);
   // printf("GCD of %d and %d is: %d",a,b,gcd(a,b));
    //printf("Fast power of %d power %d is: %ld",a,b,moduloArithematics(a,b,1000000007));
    printf("Number of ways to reach from matrix[0,0] to matrix[%d,%d] in %d * %d matrix is: %d",a,b,a,b,countWays(a,b));
    return 0;
}
