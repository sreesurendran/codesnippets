//binary tree traversal algorithms
//includes
//1. preorder traversal (recursive) / DFS
//2. inorder traversal (recursive)
//3. postorder traversal (recursive)
//4. preorder traversal (iterative) / DFS
//5. inorder traversal (iterative)
//6. postorder traversal (iterative)
//7. printing a binary tree line-by-line (BFS)

#include <iostream>

using namespace std;

#define LIM 25

namespace mybinarytree{

struct Node{
        int value;
        Node* left;
        Node* right;
        bool sign; //sign = true indicates positive and sign = false indicates negative. true by default
};

Node *root;

//STACK - for iterative tree traversal
int top = -1;
Node *stk[LIM];

//QUEUE - to print tree line-by-line
Node *que[LIM];
int rear,front;

//insert a node into the binary search tree
Node* add_node(Node *root,int value){
        Node *prev,*cur,*temp;
        temp=new Node;
        temp->value=value;
        temp->sign = true;
        temp->left=NULL;
        temp->right=NULL;

        if(root==NULL)
        {
                cout<<endl<<"Creating a tree........"<<endl;
                root=temp;
                return root;
        }
        prev=NULL;
        cur=root;
        while(cur!=NULL)
        {
                prev=cur;
                cur=(value<cur->value)?cur->left:cur->right;
        }
        if(value<prev->value)
                prev->left=temp;
        else
                prev->right=temp;
	return root;
}

//preorder traversal (R) / Depth First Search
void preorder_rec(Node *root){
        if(root!=NULL)
                cout<<"\t"<<root->value;
        else{
                cout<<endl<<"Empty tree"<<endl;
                return;
        }
        if(root->left!=NULL)
                preorder_rec(root->left);
        if(root->right!=NULL)
                preorder_rec(root->right);
}

//inorder traversal (R)
void inorder_rec(Node *root){
        if(root==NULL)
         {
                cout<<endl<<"Empty tree"<<endl;
                return;
         }
        if(root->left!=NULL)
                inorder_rec(root->left);
        cout<<"\t"<<root->value;
        if(root->right!=NULL)
                inorder_rec(root->right);
}

//postorder traversal (R)
void postorder_rec(Node *root){
        if(root==NULL)
                cout<<endl<<"Empty tree"<<endl;
        if(root->left!=NULL)
                postorder_rec(root->left);
        if(root->right!=NULL)
                postorder_rec(root->right);
        cout<<"\t"<<root->value;
}

//Helper Function for Breadth First Search
void enter_queue(Node *nnode){
        if(rear==LIM-1)
                cout<<endl<<"Queue full"<<endl;
        rear=rear+1;
        que[rear]=nnode;
}

//Helper Function for Breadth First Search
Node *exit_queue(){
        Node *nnode;
        if(front==rear)
                cout<<endl<<"Queue empty"<<endl;
        front=front+1;
        nnode=que[front];
        return(nnode);
}

//Breadth First Search (printing tree line-by-line)
void print_tree_line_by_line(Node* root){
        Node *temp,*q;
        cout<<endl;
        q=new Node;
        q->left=root;
        q->right=NULL;
        temp=q->left;
        enter_queue(temp);
        enter_queue(q);
        temp=exit_queue();
        while(front!=rear)
        {
                if(temp!=q)
                {
                        cout<<temp->value<<"\t";
                        if(temp->left!=NULL)
                                enter_queue(temp->left);
                        if(temp->right!=NULL)
                                enter_queue(temp->right);
                }
                else
                {
                        enter_queue(temp);
                        cout<<endl;
                }
                temp=exit_queue();
        }
}

//Helper Function for iterative tree traversal
void push(Node *p){
        stk[++top] = p;
}

//Helper Function for iterative tree traversal
Node* pop(){
        if(top == -1)
                return NULL;
        return stk[top--];
}

//preorder traversal (I) / Depth First Search
void preorder_iter(Node *root){
        Node *temp = NULL;
        if(root == NULL){
                cout<<endl<<"Empty Tree"<<endl;
                return;
        }
        else{
                push(root);
        }
        while(top >= 0){
                temp = pop();
                while(temp != NULL){
                        cout<<"\t"<<temp->value;
                        if(temp->right != NULL){
                                push(temp->right);
                        }
                        temp = temp->left;
                }
        }
}

//inorder traversal (I)
void inorder_iter(Node *root){
        Node *temp = NULL;
        bool isContinue = true;
        if(root == NULL){
                cout<<endl<<"Empty Tree"<<endl;
                return;
        }
        else{
                temp = root;
        }
        while(isContinue){
                isContinue = false;
                while(temp != NULL){
                        push(temp);
                        temp = temp->left;
                }
                while(top >=0){
                        temp = pop();
                        cout<<"\t"<<temp->value;
                        if(temp->right != NULL){
                                temp = temp->right;
                                isContinue = true;
                        }
                }
        }
}

//postorder traversal (I)
void postorder_iter(Node *root){
        Node *temp = NULL;
        bool isContinue = true;
        if(root == NULL){
                cout<<endl<<"Empty Tree"<<endl;
                return;
        }
        else{
                temp = root;
        }

        while(isContinue){
                isContinue = false;
                while(temp != NULL){
                        push(temp);
                        temp = temp->left;
                }

                while(top >= 0 && !(stk[top]->sign)){
                        temp = pop();
                        temp->sign = !(temp->sign);
                        cout<<"\t"<<temp->value;
                }
                if(top >= 0){
                        temp = stk[top]->right;
                        stk[top]->sign = !(stk[top]->sign);
                        isContinue = true;
                }
                else
                        isContinue = false;
        }
}

};
