/* Program to search a node with a given key in a binary search tree(BST).
 * 
 * Input: 50 30 20 40 70 60 80
 * Output: Inorder traversal of the tree is: 20 30 40 50 60 70 80
 * Searched node 40 is found
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

// function to insert new node with given key in binary search tree
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

// function for searching a node with a given key in BST
struct node* search(struct node* root, int key)
{
    // base case: if root is null or key is present at root
    if(root == NULL || root->key == key)
    {
        return root;
    }
    // if key is smaller than root's key
    if(key < root->key)
    {
        return search(root->left, key);
    }
    // if key is larger than root's key
    return search(root->right, key);
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

    printf("Inorder traversal of the tree is: ");
    inorder(root);
    printf("\n");
    
    struct node* temp = search(root, 40);
    if(temp)
    {
        printf("Searched node %d is found\n", temp->key);
    }
    else
    {
        printf("Key not found in the BST\n");
    }
    return 0;
}
