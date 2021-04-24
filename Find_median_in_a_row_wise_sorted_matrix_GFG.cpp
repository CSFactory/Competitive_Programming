//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here     
        int arr[r*c];
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[k] = matrix[i][j];
                k++;
            }
        }
        
       //sort the array
       sort(arr,arr+(r*c));
        return (arr[k/2]);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
