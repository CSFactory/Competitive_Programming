//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    // 1 3 4 7 9 9 12 56
    //2 3 4 7 9 12 56
    long long temp=0;
    //Sort the array //If Swapping is used then TLE,
    //so that's why using inbuilt sort vector functionality of c++
   /* for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }*/
    sort(a.begin(), a.end());
    /*for(int p=0;p<n;p++){
        printf("%d ",a[p]);
    }
    printf("\n"); */
    long long arr_diff[n]; //array of differences
    long long min_diff = 0;
    long long count=0;
    if(n!=m){
           for(long long k=0,t=m-1;k<m-1,t<n;k++,t++){
                if(t<n){
                     arr_diff[k] = (abs(a[k]-a[t]));
                     count++;
                }
                else{
                    break;
                }
            }
            min_diff = arr_diff[0];
            for(long long g=0;g<count;g++){
                if(min_diff>arr_diff[g]){
                    min_diff = arr_diff[g];
                }
               // printf("ad = %d\n",arr_diff[g]);
            } 
            
    }
    else if (n==m){
        min_diff = abs(a[0]-a[n-1]);
    }
    return min_diff;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends
