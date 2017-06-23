/* Program to delete a node with a key from Binary Search Tree.
 *
 * Input: 50 30 20 40 70 60 80
 * Output: Delete 50
 * Inorder Traversal of BST: 20 30 40 50 60 70 80
 * Inorder Traversal of modified BST: 20 30 40 60 70 80
 */

 #include <stdio.h>
 #include <stdlib.h>

 struct node
 {
     int key;
     struct node *left;
     struct node *right;
 };

 struct node* newNode(int item)
 {
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp->key = item;
     temp->right = temp->left = NULL;
     return temp; 
 }

 struct node* insert(struct node* node, int key)
 {
    if(node == NULL)
    {
         return newNode(key);
    }
    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
 }

void inorder(struct node* root)
{   
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// function deleted the key and returns the new root
 struct node* deleteNode(struct node* root, int key)
 {
     // base case 
     if (root == NULL)
     {
         return root;
     }
     if(key < root->key)
     {
         root->left = deleteNode(root->left, key);
     }
     else if(key > root->key)
     {
         root->right = deleteNode(root->right, key);
     }
     else
     {
         if (root->left == NULL)
         {
             struct node* temp = root->right;
             free(root);
             return temp;
         }
         else if(root->right == NULL)
         {
             struct node* temp = root->left;
             free(root);
             return temp;
         }
         struct node* temp = minValueNode(root->right);
         root->key = temp->key;
         root->right = deleteNode(root->right, temp->key);
     }
     return root;
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

     printf("Inorder Traversal of BST: ");
     inorder(root);
     root = deleteNode(root, 30);
     printf("\nInorder Traversal of modified BST: ");
     inorder(root);
     printf("\n");
     return 0;
 }
