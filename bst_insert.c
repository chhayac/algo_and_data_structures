/* Program to insert nodes with given keys in binary search trees.
 * 
 * Input: 50 30 20 40 70 60 80
 * Output: 20 30 40 50 60 70 80
 */


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// function to create new Binary search tree node
struct node* newNode(int item)
{
    struct node* temp = (struct node *) malloc(sizeof(struct node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

// function for inorder traversal of binary search tree
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// function to insert new node with given key in  binary search tree
struct node* insert(struct node* node, int key)
{
    //if tree is empty, return new node
    if(node == NULL)
    {
        return newNode(key);
    }
    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;       
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    printf("\n");
    return 0;
}
