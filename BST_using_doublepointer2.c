#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data)
        insert(&(*root)->left, data);
    else if (data > (*root)->data)
        insert(&(*root)->right, data);
}

// Function to perform inorder traversal of the binary search tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to deallocate memory of the binary search tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes;
    int data;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    // Print the nodes of the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Deallocate memory of the binary search tree
    freeTree(root);

    return 0;
}
