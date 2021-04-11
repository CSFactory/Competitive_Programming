/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
int arr[10000]; //As maximum constraint was of 10K elements in the tree.
int i = 0;
int flag=-1;
int calc = 0;
	bool checkBST(Node* root) {
		if(root==NULL){
            return -1;
        }
        else{
            checkBST(root->left);
            arr[i] = (root->data);
            i++;
            checkBST(root->right);
        }
        calc = i-1;
        for(int j=0;j<calc;j++){
            if(arr[j]<arr[j+1]){
                flag=1;
            }
            else{
                flag=0;
                break;
            }
        }
        return flag;
	}
