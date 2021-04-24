//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ind;
    //first occurence
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            ind.push_back(i);
            break;
        }
        else if((arr[i]!=x) && (i==n-1)){
            ind.push_back(-1);
        }
    }
    //last occurence
    for(int j=n-1;j>=0;j--){
        if(arr[j]==x){
            ind.push_back(j);
            break;
        }
        else if((arr[j]!=x) && (j==0)){
            ind.push_back(-1);
        }
    }
    return ind;
}
