/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct trie{
    bool isend;
    struct trie *child[26];
    
    trie(){
        memset(child,0,sizeof(child));
        isend = false;
    }
};


struct trie* root;

void insert(string str){
     
    struct trie* current;
    current=root;
    int len = str.length();
    for(int i=0;i<len;i++){
        int idx = str[i]-'a';
        if(current->child[idx]==NULL){
            struct trie* newtrie = (struct trie*)malloc(sizeof(trie));
            current->child[idx] = newtrie;
        }
        current = current->child[idx];
    }
    current->isend = true;
}

bool search(string dd){
    struct trie* current;
    current  = root;
    for(int i=0;i<dd.length();i++){
        int idx = dd[i]-'a';
        if(current->child[idx]==NULL){
            return false;
        }
        else{
            current = current->child[idx];
        }
    }
    return (current->isend);
}

int main()
{
    long long int n;
    cin>>n;
    //root = (struct trie*)malloc(sizeof(struct trie));
    root=new trie;
    while(n--){
        string str;
        cin>>str;
        insert(str);
    }
    
    int s;
    cin>>s;
    while(s--){
        string dd;
        cin>>dd;
        if(search(dd)){
            cout<<dd<<" is present\n";
        }
        else{
            cout<<dd<<" is not present\n";
        }
    }
    return 0;
}
