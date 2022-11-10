 #include<iostream>
 using namespace std;

//  GFG
   struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

    int isSumProperty(Node *root)
    {
     // Add your code here
        if(root==NULL) return 1;
        if(root->left==NULL && root->right==NULL) return 1;
        int leftChild=root->left ? root->left->data:0;
        int rightChild=root->right ? root->right->data:0;
        return root->data==leftChild+rightChild && isSumProperty(root->left) && isSumProperty(root->right) && root->data==leftChild+rightChild ;
    }