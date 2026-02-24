#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // For INT_MIN error handling

typedef struct Node { 
    struct Node* left; 
    int data; 
    struct Node* right; 
} Node;

typedef struct Tree{
    Node* root; 
} Tree;

// Initializes an empty tree
Tree* createTree() { 
    Tree* tree = (Tree*)malloc(sizeof(Tree)); 
    if (!tree) return NULL; 
    tree->root = NULL; 
    return tree; 
}   

// Returns true if tree has no elements
bool isEmpty(Tree* tree) {
    return tree->root == NULL;
}

// Adds a new value to the tree
void add(Tree* tree, int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (!newNode) return;

    // 1. Initialize EVERYTHING immediately
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // 2. Now just find where it goes
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        Node* current = tree->root;
        while (true) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
}


// Removes and returns the top value
void freeNodes(Node* node) {
    if (node == NULL) return;
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}

void freeTree(Tree* tree) {
    freeNodes(tree->root);
    free(tree);
}


void inOrderRecursive(Node* root) {
    if (root == NULL) return;
    inOrderRecursive(root->left);     
    printf("%d  ", root->data);
    inOrderRecursive(root->right);
}

// Wrapper for the main call
void inOrder(Tree* tree) {
    inOrderRecursive(tree->root);
    printf("\n");
}

void preOrderRecursive(Node* root) {
    if (root == NULL) return;
    printf("%d  ", root->data);
    preOrderRecursive(root->left);     
    preOrderRecursive(root->right);
}

// Wrapper for the main call
void preOrder(Tree* tree) {
    preOrderRecursive(tree->root);
    printf("\n");
}


void postOrderRecursive(Node* root) {
    if (root == NULL) return;
    postOrderRecursive(root->left);     
    postOrderRecursive(root->right);
    printf("%d  ", root->data);
}

// Wrapper for the main call
void postOrder(Tree* tree) {
    postOrderRecursive(tree->root);
    printf("\n");
}

int main(void) { 
    Tree* tree = createTree(); 
    
    add(tree, 3);
    add(tree, 9);
    add(tree, 2); 
    add(tree, 5);
    add(tree, 1);
    
    printf("In-order traversal: \n");
    inOrder(tree); 

    printf("Pre-order traversal: \n");
    preOrder(tree); 

    printf("Post-order traversal: \n");
    postOrder(tree);

    freeTree(tree); 
    return 0; 
}
