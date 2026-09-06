#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int value;
	node*left;
	node*right;
};

//Function to find minimum in a tree. 
node* FindMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct node* Delete(node* root , int data)
{
	if(root==NULL)
	{
		return root;
	}
	
	else if(data < root->value)
	{
		root->left = Delete(root->left,data);
	}
	
	else if(data > root->value)
	{
		root->right = Delete(root->right,data);
	}
	
	else
	{	// Case 1:  No child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//Case 2: One child	
		else if (root->left == NULL)
		{
			node* temp = root; 
			root = root->right;
			delete temp;
		}
		
		else if (root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else
		{
			node* temp = FindMin(root->right);
			root->value = temp->value;
			root->right = Delete(root->right,temp->value);
		}
	}
return root;
}


//previous part
//Function to visit nodes in Inorder
void Inorder(node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	cout<<root->value <<"\t";  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert node in a Binary Search Tree
node* Insert(node *root,char data) {
	if(root == NULL) {
		root = new node();
		root->value = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->value)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	            6
			   / \
			  4   11
			 / \   \
			2   5   12
    */
	node* root = NULL;
	root = Insert(root,6); 
	root = Insert(root,11);
	root = Insert(root,4); 
	root = Insert(root,5); 
	root = Insert(root,2); 
	root = Insert(root,12);
	//Print nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	// Deleting node with value 6, change this value to test other cases
	root = Delete(root,6);

	//Print nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}



