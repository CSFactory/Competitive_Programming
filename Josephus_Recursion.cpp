#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k){ //Goli maar bheje mein upto k
    if(n==1){
        return 0;
    }
    return ((josephus(n-1,k)+k)%n);
}

int main()
{
    printf("Final Member jo Bach gya is: %d",josephus(5,3));
    return 0;
}
