//https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int position = 0;
        int count_set_bits = 0;
        while(N){
            if((N%2)==1){
                count_set_bits++;
            }
            position++;
            N=N/2;
        }
        if(count_set_bits!=1){
            position = -1;
        }
        
        return position;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
