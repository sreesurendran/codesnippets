/*

You are given a sorted list of numbers with duplicates. Print out the sorted list with duplicates removed.

*/

#include <iostream>
#include <list>

using namespace std;

void printUnique(list<string> input){

	string prev = "";
	const char* prefix = "";
	for(auto ii=input.begin();ii!=input.end();ii++){
		if(prev != *ii)
			cout<<prefix<<*ii;
		prev = *ii;
		prefix = ",";
	}

}



int main(int argc, char* argv[]){

	if(argc == 1){
		cout<<endl<<"Enter array"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		list<string> input(argv,argc+argv);
		input.pop_front();
		printUnique(input);
		cout<<endl;
		return 0;
	}

}
