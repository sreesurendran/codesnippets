//check whether a given string is a palindrome
//sample command-line invocation: ./a.out radar
#include <iostream>

using namespace std;

//iterative
bool isPalindrome_iterative(string input){
	for(int a=0,z=input.size()-1;a<z;a++,z--){
		if(input[a] != input[z])
			return false;
	}
	return true;
}

//recursive
bool isPalindrome_recursive(string input,int start,int end){
	if(start >= end)
		return true;
	else{
		if(input[start] == input[end])
			return isPalindrome_recursive(input,start+1,end-1);
		else
			return false;
	} 
}

int main(int argc,char* argv[]){
	cout<<endl;
	if(argc < 2){
		cout<<endl<<"Enter string"<<endl;
		return 0;
	}
	else{
		bool isPI = isPalindrome_iterative(argv[1]);
		if(isPI)
			cout<<endl<<"Is Palindrome (I)";
		else
			cout<<endl<<"Is not palindrome (I)";
		
		string input(argv[1]);
		bool isPR = isPalindrome_recursive(input,0,input.size()-1);
                if(isPR)
                        cout<<endl<<"Is Palindrome (R)";
                else
                        cout<<endl<<"Is not palindrome (R)";
	}
	cout<<endl;
	return 0;
}
