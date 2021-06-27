https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& A) {
        stack<char> st; //create a stack
        //pushing characters of string into the stack
        for(int i=0;i<A.size();i++){
            st.push(A[i]);
        }
        //pop the characters from the stack
        for(int i=0;i<A.size();i++){
            A[i] = st.top();
            st.pop();
        }
    }
};
