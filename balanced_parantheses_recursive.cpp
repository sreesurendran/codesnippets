/*

you should code your solution so that it embodies the recursive insight that a string consisting only of
bracketing characters is balanced if and only if one of the following conditions holds:
• The string is empty.
• The string contains “()”, “[]”, or “fg” as a substring and is balanced if you remove that substring.
For example, the string “[()fg]” is shown to be balanced by the following chain of calls:
isBalanced("[()fg]")
isBalanced("[fg]")
isBalanced("[]")
isBalanced("") ->  true
You may assume that there are no characters other than bracketing operators in the input string.

*/


#include <iostream>

using namespace std;


//recursive
bool isBalanced(string input){

	if(input.size() == 0)
		return true;

	size_t pos = -1;
	if(input.find("()") != string::npos)
		pos = input.find("()");
	else if(input.find("[]") != string::npos)
		pos = input.find("[]");
	else if(input.find("{}") != string::npos)
		pos = input.find("{}");		
				
	if(pos != -1)
		return isBalanced(input.substr(0,pos) + input.substr(pos+2));

	return false;
}

int main(int argc, char* argv[]){

	if(argc == 1){
		cout<<endl<<"Enter string"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		string input(argv[1]);
		cout<<endl<<std::boolalpha<<isBalanced(input)<<endl;
		cout<<endl;
		return 0;
	}

}
