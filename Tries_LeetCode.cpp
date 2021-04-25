//https://leetcode.com/problems/implement-trie-prefix-tree/

struct TrieNode {
    TrieNode *child[26];
    bool isend;
    
    TrieNode() {
        memset(child,0,sizeof(child));
        isend = false;
    }
};
    
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current;
        current = root;
        for(int i=0;i<(word.length());i++){
            int idx = word[i]-'a';
            if(current->child[idx]==NULL){
                TrieNode* newtrie = new TrieNode();
                current->child[idx] = newtrie;
            }
            current = current->child[idx];
        }
        current->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current;
        current = root;
         for(int i=0;i<word.length();i++){
            int idx = word[i]-'a';
            if(current->child[idx]==NULL){
                return false;
            }
            else{
                current = current->child[idx];
            }
         }
        return current->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current;
        current = root;
         for(int i=0;i<(prefix.length());i++){
            int idx = prefix[i]-'a';
            if(current->child[idx]==NULL){
                return false;
            }
            else{
                current = current->child[idx];
            }
         }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
