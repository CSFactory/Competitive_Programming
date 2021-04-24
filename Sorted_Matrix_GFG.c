//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int length = N*N;
        int arr[length];
        int k=0,t=0;
       for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr[k] = Mat[i][j];
                k++;
            }
        }
        
        //sort the array
       sort(arr,arr+(N*N));
        for(int l=0;l<N;l++){
            for(int m=0;m<N;m++){
                Mat[l][m] = arr[t];
                t++;
            }
        }
     return Mat;   
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends
