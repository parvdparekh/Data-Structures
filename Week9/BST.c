#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};
struct TreeNode* newnode;
void createNode(int val, struct TreeNode* root)
{
    if(val<root->val)
    {
        if(root->left==NULL)
        {
            newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            newnode->right=NULL;
            newnode->left=NULL;
            newnode->val=val;
            root->left=newnode;
        }
        else
            createNode(val,root->left);
    }
    else
    {
        if(root->right==NULL)
        {
            newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            newnode->right=NULL;
            newnode->left=NULL;
            newnode->val=val;
            root->right=newnode;
        }
        else
            createNode(val,root->right);
    }
}

void preorder(struct TreeNode* root)
{
    if(root==NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void postorder(struct TreeNode *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

void main()
{
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=1;
    root->left=NULL;
    root->right=NULL;
    createNode(-20,root);
    createNode(-80,root);
    createNode(60,root);
    createNode(7,root);
    createNode(25,root);
    createNode(4,root);
    createNode(16,root);
    printf("Preorder:\n");
    preorder(root);
    printf("\n\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n\n");
    printf("Inorder:\n");
    inorder(root);
}
