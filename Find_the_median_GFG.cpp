//https://practice.geeksforgeeks.org/problems/find-the-median0527/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    int median = 0;
		    sort(v.begin(),v.end());
		    if(v.size()>2){
		        if(((v.size())%2)!=0){
		            median = v[((v.size())/2)];
		        }
		        else{
		            median = ((v[(v.size()/2)-1]+v[(v.size()/2)])/2);
		        }
		    }
		    else if(v.size()==2){
		        median = ((v[0]+v[1])/2);
		    }
		    
		    return median;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
