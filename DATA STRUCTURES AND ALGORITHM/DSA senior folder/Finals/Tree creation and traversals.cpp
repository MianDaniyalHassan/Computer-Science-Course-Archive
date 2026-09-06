#include <iostream>
using namespace std;

// Structure to define a node in the binary tree
struct Node {
    int value;      // Value stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
};

// Function to create a binary tree
Node* createTree() {
    int x;
    cout << "Enter the value for the node (-1 for no node): ";
    cin >> x;

    // If the user inputs -1, return NULL (no node created)
    if (x == -1) {
        return NULL;
    }

    // Create a new node and assign the value
    Node* newNode = new Node();
    newNode->value = x;

    // Recursively create left and right subtrees
    cout << "Enter left child of " << x << ": ";
    newNode->left = createTree();
    cout << "Enter right child of " << x << ": ";
    newNode->right = createTree();

    return newNode;
}

// Function for pre-order traversal (Root -> Left -> Right)
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function for post-order traversal (Left -> Right -> Root)
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

// Function for in-order traversal (Left -> Root -> Right)
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Function to search for a value in the binary tree
// Function to search for a value in the binary tree
Node* searchTree(int value, Node* root) {
    if (root == NULL) {  // Base case: Reached a null node
        return NULL;
    }

    if (root->value == value) {  // Value found at the current node
        cout << "Value found: " << value << endl;
        return root;
    }

    // Recursively search in the left subtree
    Node* leftSearch = searchTree(value, root->left);
    if (leftSearch != NULL) {  // If found in the left subtree, return the result
        return leftSearch;
    }

    // Recursively search in the right subtree
    return searchTree(value, root->right);
    

	}
// Main function
int main() {
    Node* root = NULL;  // Initialize the root of the binary tree to NULL

    // Create the binary tree
    cout << "Creating the binary tree..." << endl;
    root = createTree();

    // Perform different traversals
    cout << "\n------------------------------------------------------------\n";
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);

    cout << "\nPost-order Traversal: ";
    postOrderTraversal(root);

    cout << "\nIn-order Traversal: ";
    inOrderTraversal(root);

    cout << "\n------------------------------------------------------------\n";

    // Search for a value in the binary tree
    int valueToSearch = 9;  // Example value to search
    cout << "Searching for value " << valueToSearch << " in the tree..." << endl;
    searchTree(valueToSearch, root);

    return 0;
}

