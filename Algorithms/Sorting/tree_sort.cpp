//Tree Sort Algorithm
//Language Used: C++
//Tree Sort Algorithm uses Inorder Traversal of a Binary Search Tree to sort elements in ascending order
//Input Format: First line contains size of array, second line contains array elements
//Output Format: Output contains only one line i.e., sorted array of elements
//Sample Input:  5
//               3 9 0 1 5
//Sample Output: 0 1 3 5 9
//author: adiXcodr

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


void treeSort(int arr[], int len)
{
	struct Node *root = NULL;
	root = insert(root, arr[0]);

	for (int i=1; i<len; i++)
        insert(root, arr[i]);

	int i = 0;
	storeSorted(root, arr, i);
}


int main()
{
  int len;
  cout<<"Enter the Number of Elements ";
  cin>>len;
  int arr[len];

  cout<<"Enter The Elements ";
  for (int i=0; i<len; i++)
	  cin>>arr[i];

  treeSort(arr, len);
  //Display Sorted Values
  cout<<"Sorted:\n";

  for (int i=0; i<len; i++)
     cout << arr[i] << " ";

	return 0;
}
