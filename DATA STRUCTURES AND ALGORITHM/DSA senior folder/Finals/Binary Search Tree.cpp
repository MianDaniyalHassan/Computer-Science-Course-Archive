#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " -> ";
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " -> ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " -> ";
    }
}

// Insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Find the node with the minimum key
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);

        // Copy the inorder successor's key to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
    
}
    
    // Function to search for a value in the binary tree
Node* searchTree(int value, Node* root) {
    if (root == NULL) {  // Base case: Tree is empty or value not found
        cout << "Value not found." << endl;
        return NULL;
    }

    if (root->key == value) {  // Value found at the current node
        cout << "Value found: " << value << endl;
        return root;
    }

    if (value < root->key) {  // Search in the left subtree
        return searchTree(value, root->left);
    }

    // Search in the right subtree
    return searchTree(value, root->right);
}


int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    
     
    // Search for a value in the binary tree
    int valueToSearch = 10;  // Example value to search
    cout << "Searching for value " << valueToSearch << " in the tree..." << endl;
    searchTree(valueToSearch, root);

    cout << "Deleting 10...\n";
    root = deleteNode(root, 6);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
   

    return 0;
}

