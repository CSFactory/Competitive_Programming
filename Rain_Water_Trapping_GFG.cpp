// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

#include<math.h>
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int left[n];
        int right[n];
        //left array
        left[0] = arr[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        //right array
        right[n-1]=arr[n-1]; //copying last element
        for(int j=n-2;j>=0;j--){
            right[j] = max(right[j+1],arr[j]);
        }
        //main logic
        int trapped_water=0;
        for(int k=0;k<n;k++){
            trapped_water += (min(left[k],right[k])-arr[k]);
        }
        return trapped_water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
