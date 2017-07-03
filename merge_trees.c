/* Given two binary trees and imagine that when you put 
 * one of them to cover the other, some nodes of the two trees are overlapped while 
 * the others are not.
 *
 * You need to merge them into a new binary tree. The merge rule is that if 
 * two nodes overlap, then sum node values up as the new value of the merged node. 
 * Otherwise, the NOT null node will be used as the node of new tree.
 *
 * Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
 * Output: 
 * Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 * Note: The merging process must start from the root nodes of both trees.
 * Output: 
 * Inorder traversal of the merged tree is: 5 4 4 3 5 7
 */

#include <stdio.h>
#include <stdlib.h>

// definition of a Binary tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

// function to create new node
struct TreeNode* newNode(int data)
{
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to merge trees
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL) {
        return t2;
    }

    if (t2 == NULL) {
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left:NULL);
    t1->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
    return t1;
}

void inorder(struct TreeNode* root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main()
{
    // create 1st Binary Tree
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->left->left = newNode(5);

    // create 2nd Binary Tree
    struct TreeNode* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);
    root2->left->right = newNode(4);
    root2->right->right = newNode(7);

    struct TreeNode* mergedTree = mergeTrees(root1, root2);
    printf("Inorder traversal of the merged tree is: ");
    inorder(mergedTree);
    printf("\n");
    return 0;
}
