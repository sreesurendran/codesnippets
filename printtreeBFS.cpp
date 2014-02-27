#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int value;
	Node* left;
	Node* right;
};

Node* root;

//add node to BST
Node* add_node(int value){
	Node *prev, *cur, *temp;
	temp = new Node;
	temp->value = value;
	temp->left = nullptr;
	temp->right = nullptr;
	
	if(root == nullptr){
		root = temp;
		return root;
	}

	cur = root;
	prev = nullptr;

	while(cur != nullptr){
		prev = cur;
		cur = (value < cur->value)?cur->left:cur->right;
	}
	if(value < prev->value)
		prev->left = temp;
	else
		prev->right = temp;
	return root;
}

void print_level_by_level(Node* root){

	if(root == nullptr)
		return;

	int nCurrentLevel = 1;
	int nNextLevel = 0;

	queue<Node*> procQ;
	procQ.push(root);

	while(!procQ.empty()){
		Node* currNode = procQ.front();
		procQ.pop();
		nCurrentLevel--;

		if(currNode){
			cout<<currNode->value<<",";
			procQ.push(currNode->left);
			procQ.push(currNode->right);
			nNextLevel += 2;
		}
		
		if(nCurrentLevel == 0){
			cout<<endl;
			nCurrentLevel = nNextLevel;
			nNextLevel = 0;
		}	
	}	

}

int main(){

	cout<<endl;
	char isContinue = 'n', ans = 'n';
	int ch,value;
	do{
		cout<<endl<<"Menu"<<endl;
		cout<<"1. Create BST"<<endl;
		cout<<"2. Insert node"<<endl;
		cout<<"3. Print tree level by level"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				root = nullptr;
				do{
					cout<<endl<<"Enter number:";
					cin>>value;
					add_node(value);
					cout<<endl<<"Do you wish to enter another number?(y/n):";
					cin>>ans;
				}while(ans != 'n');
				break;
			case 2:
				cout<<endl<<"Enter number:";
				cin>>value;
				add_node(value);
				break;
			case 3:
				print_level_by_level(root);
				break;
			case 4:
			default:
				exit(0);
				break;
		}
		cout<<endl<<"Do you wish to return to the menu?(y/n):";
		cin>>isContinue;
	}while(isContinue != 'n');
	cout<<endl;
	return 0;
}
