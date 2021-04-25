//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
    int no_of_nodes=0;
    struct Node* current, *temp;
    current = head;
    temp = head;
    while(current!=NULL){
        no_of_nodes++;
        current=current->next;
    }
    int final_datapoint;
    int counter = ((no_of_nodes-n)+1);
    if(no_of_nodes>=n){
        while(counter!=1){
            temp = temp->next;
            counter--;
        }
        final_datapoint = (temp->data);
    }
    else{
        final_datapoint = -1;
    }

    return final_datapoint;
}

