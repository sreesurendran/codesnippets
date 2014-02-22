//interesting way to check whether a string is a palindrome using a stack and queue (https://www.cs.bu.edu/teaching/c/tree/breadth-first/)

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main(int argc,char* argv[]){
	
	queue<string> palQueue;
	stack<string> palStack;
	for(int i=1;i<argc;i++){
		palQueue.push(argv[i]);
		palStack.push(argv[i]);
	}
	cout<<endl;
	bool isPal = true;
	for(int i=1;i<argc;i++){
		string queElem = palQueue.front();
		palQueue.pop();
		string stkElem = palStack.top();
		palStack.pop();
		if(queElem != stkElem){
			isPal = false;
			break;
		}
	}
	if(isPal)
		cout<<endl<<"Is a palidrome";
	else
		cout<<endl<<"Is not a palindrome";
	
	cout<<endl;
	return 0;
}
