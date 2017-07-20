/* Print a binary tree in vertical order.
 * Input :
 *         1
 *       /    \
 *      2      3
 *     / \    / \
 *    4   5  6   7
 *            \   \
 *             8   9 
 *              		  
 * Output : The output of printing a binary tree vertically will be:
 * 4
 * 2
 * 1 5 6
 * 3 8
 * 7
 * 9 
 */

#include <stdio.h>
#include <stdlib.h>

// A node of Binary tree
struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new binary tree node
struct Node* newNode(int data)
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the minimum and maximum horizontal distance of node 
// from the root.
// hd is horizontal distance of current node from the root
void findMinMax(struct Node *node, int *min, int *max, int hd)
{
    // Base case
    if(node == NULL)
    {
        return;
    }

    // Update minimum and maximum
    if (hd < *min)
    {
        *min = hd;
    }
    else if(hd > *max)
    {
        *max = hd;
    }

    // Recur for left and right subtrees
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}

// Function to print all nodes on a given line number
void printVerticalLine(struct Node *node, int line_no, int hd)
{
    // Base case
    if(node == NULL)
    {
        return;
    }

    // If the node is on the given line number
    if(hd == line_no)
    {
        printf("%d ", node->data);
    }

    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}

// Main function that prints a given binary tree in vertical order
void verticalOrder(struct Node* root)
{   
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines from the
    // leftmost line to the rightmost line and prints nodes line by line
    for(int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

int main()
{
    // Create binary tree 
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    printf("Vertical order Traversal: \n");
    verticalOrder(root);
    return 0;
}
