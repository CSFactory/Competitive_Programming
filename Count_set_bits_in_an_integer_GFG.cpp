//https://practice.geeksforgeeks.org/problems/set-bits0143/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int counter=0;
        while(N){
            if((N%2)==0){
                N=N/2;
            }
            else if((N%2)!=0){
                counter++;
                N=N/2;
            }
        }
        return counter;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends
