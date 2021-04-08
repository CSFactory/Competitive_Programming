#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int getHeight(struct node* root) {
    // Write your code here
    int height=0;
    int lstheight=0;
    int rstheight=0;
    
    if(root==NULL){
        height=-1;
    }
    else{
        
       //  printf("\tlst_N=%d\n",root->data);
         //1
        lstheight=getHeight(root->left); //1.1
        lstheight++; //1.2
       // printf("\tlst_h=%d\n",lstheight); 
        //2
        rstheight=getHeight(root->right);//2.1
        rstheight++; //2.2
      // printf("\trst_h=%d\n",rstheight);
       //3
        if(lstheight>rstheight){
            height=lstheight;
        }
        else{
            height=rstheight;
        }
    }
   // printf("h=%d\n",height);
    return height;
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	printf("%d",getHeight(root));
    return 0;
}
