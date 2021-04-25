//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        struct Node *dataloadnode;
        dataloadnode = head;
        int dataArr[100];
        int k=0;
        while(dataloadnode!=NULL){
            dataArr[k] = dataloadnode->data;
            k++;
            dataloadnode = dataloadnode->next;
        }
        int processArr[100];
        int l=0;
        //even
        for(int i=0;i<k;i++){
            if((dataArr[i]%2)==0){
                processArr[l] = dataArr[i]; 
                l++;
            }
        }
        //odd
        for(int j=0;j<k;j++){
            if((dataArr[j]%2)!=0){
                processArr[l] = dataArr[j]; 
                l++;
            }
        }
        
        //test
        struct Node* hello = NULL;
        for(int t=k-1;t>=0;t--){
            struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
            newnode->data = processArr[t];
            newnode->next = hello;
            hello = newnode;
        }

        return hello;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
