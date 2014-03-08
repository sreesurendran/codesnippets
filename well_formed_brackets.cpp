/*

The task is to write a function Brackets(int n) that prints all combinations of well-formed brackets from 1...n. For Brackets(3) the output would be

()
(())  ()()   
((()))  (()())  (())()  ()(())  ()()()

Solution:

The recursion is taking advantage of the fact that you can never add more opening brackets than the desired number of pairs, and you can never add more closing brackets than opening brackets.


*/

#include <iostream>

using namespace std;

void brackets(string output,int open,int close,int pairs){

	if(open == pairs && close == pairs)
		cout<<endl<<output;
	else{
		if(open<pairs)
			brackets(output+"(",open+1,close,pairs);
		if(close<open)
			brackets(output+")",open,close+1,pairs);
	}
}


int main(int argc, char* argv[]){

	if(argc == 1){
		cout<<endl<<"Enter n"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		int n = atoi(argv[1]);
		for(int i=1;i<=n;i++)
			brackets("",0,0,i);
		cout<<endl;
		return 0;
	}
}
