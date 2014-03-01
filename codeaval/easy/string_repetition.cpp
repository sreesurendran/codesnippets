/*
Determine the shortest repetition in a string.

A string is said to have period p if it can be formed by concatenating one or
more repetitions of another string of length p. For example, the string
"xyzxyzxyzxyz" has period 3, since it is formed by 4 repetitions of the string
"xyz". It also has periods 6 (two repetitions of "xyzxyz") and 12 (one
repetition of "xyzxyzxyzxyz").

*/

#include <iostream>
#include <string>

using namespace std;

int getShortestPeriod(string input){
	
        for(int i=1;i<=input.size()/2;i++){
        	string period = input.substr(0,i);
		string temp = input;
		bool isFound = true;
                while(isFound && temp.size() > 0){
			if(temp.find(period) != string::npos){
				temp = temp.substr(i);
			}
			else{
				isFound = false;
			}
		}
                if(isFound)
                        return i;
	}
	return 0;
}

int main(int argc, char* argv[]){

	cout<<endl;
	if(argc < 2){
		cout<<endl<<"Enter string"<<endl;
		return 0;
	}
	else{
		string input(argv[1]);
		int period = getShortestPeriod(input);
		cout<<endl<<"Period:"<<period;
	}
	cout<<endl;
	return 0;

}
