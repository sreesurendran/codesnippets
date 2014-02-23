//Complexity: O(n)

//check for sorted linked list to BST: http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

#include <iostream>
#include "binarytree.h"
#include <vector>

using namespace std;
using namespace mybinarytree;

Node* newNode(int value){
	Node *temp = new Node;
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
}

Node* sortedArrayToBST(vector<int> input,int start,int end){
	if(start>end){
		return NULL;
	}
	int mid = (start+end)/2;
	Node* root = newNode(input[mid]);
	root->left = sortedArrayToBST(input,start,mid-1);
	root->right = sortedArrayToBST(input,mid+1,end);
	return root;
}

int main(){
	cout<<endl;
	vector<int> input = {1,2,3,4,5};
	Node* root = sortedArrayToBST(input,0,input.size()-1);
	print_tree_line_by_line(root);
	cout<<endl;
	return 0;
}
