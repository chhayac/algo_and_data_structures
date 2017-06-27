/* Program to check if a binary tree is BST or not.
 * Example:
 * Input: 4 2 5 1 3
 * Min = 1 , Max = 5
 * Output: Binary Tree is a Binary Search Tree
 */

 #include <stdio.h>
 #include <stdlib.h>
 #define true 1
 #define false 0
 struct node
 {
     int key;
     struct node *left;
     struct node *right;
 };

 int isBSTUtil(struct node* node, int min, int max);

 int isBST(struct node* node)
 {
    return (isBSTUtil(node, 1, 5));
 }

 int isBSTUtil(struct node *node, int min, int max)
 {
    if (node == NULL)
    {
        return 1;
    }
    if(node->key < min || node->key > max)
    {
        return 0;
    }
    return isBSTUtil(node->left, min, node->key-1) && isBSTUtil(node->right, node->key+1, max);
 }
 
 struct node* newNode(int item)
 {
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp->key = item;
     temp->left = temp->right = NULL;
     return temp;
 }

 int main()
 {
     struct node* root = newNode(4);
     root->left = newNode(2);
     root->right = newNode(5);
     root->left->left = newNode(1);
     root->left->right = newNode(3);

     if(isBST(root))
     {
         printf("Binary Tree is a Binary Search Tree.\n");
     }
     else
     {
         printf("Binary tree is not a Binary Search Tree\n");
     }
    return 0;
 }
