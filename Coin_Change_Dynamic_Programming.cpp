/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;

int minCount(int rs, int denomination[], int dp[]){
    
    //Base case
    if(rs==0){ 
        return 0; 
    }
    
    int ans = INT_MAX;
    

    for(int i=0;i<3;i++){
        if(rs-denomination[i]>=0){
            int subAns = 0;
            if(dp[rs-denomination[i]] != -1){
                subAns = dp[rs-denomination[i]];
            }
            else{
                 subAns = minCount((rs-denomination[i]),denomination,dp);
            }
            
            if((subAns+1 <= ans) && (subAns != INT_MAX)){
                ans  = subAns + 1;
            }
        }
    }
    
    dp[rs] = ans;
    return ans;
}

int main()
{
    int rp = 18;
    int deno[3] = {5,1,7};
    int d[rp+1];
    fill(d,d+rp,-1);
    d[0]=0;
    int countMin = minCount(rp,deno,d);
    cout<<"Minimum Coins required to complete the rs is/are: "<<countMin<<"\n";
    
    for(int i=0;i<=rp;i++){
        cout<<d[i]<<"__"<<i<<"\n";
    }

    return 0;
}
