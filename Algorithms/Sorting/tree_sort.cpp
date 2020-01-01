#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// Create New Node
struct Node *newNode(int item) 
{ 
	struct Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Storing Inorder traversal in array
void storeSorted(Node *root, int arr[], int &i) 
{ 
	if (root != NULL) 
	{ 
		storeSorted(root->left, arr, i); 
		arr[i++] = root->key; 
		storeSorted(root->right, arr, i); 
	} 
} 

//Inserting Value to tree
Node* insert(Node* node, int key) 
{ 
	
	if (node == NULL) 
    return newNode(key); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	return node; 
} 

 
void treeSort(int arr[], int n) 
{ 
	struct Node *root = NULL; 
	root = insert(root, arr[0]); 

	for (int i=1; i<n; i++) 
		  insert(root, arr[i]); 

	int i = 0; 
	storeSorted(root, arr, i); 
} 


int main() 
{ 
  int n;
  cout<<"BST SORT";
	cout<<"\nEnter the Number of Elements ";
  cin>>n;
  int arr[n];
  cout<<"Enter The Elements ";
  for (int i=0; i<n; i++) 
	  cin>>arr[i];
	treeSort(arr, n); 
  //Display Sorted Values
	for (int i=0; i<n; i++) 
	  cout << arr[i] << " "; 

	return 0; 
} 
