/* Use recursion with backtracking. Each time we try to encode the first digit in the message to a letter, or we can encode the first two digits into a letter if possible, we then recursively do the samething for the sub-string. When there is no way to encode (e.g., encountering a single ’0′, or encountering ’32′ and tyring to encode the two-digits to a letter), we simply return. If there is no sub-string to go on, we know we have found a valid solution, so we increase the count.

*/

#include <iostream>

using namespace std;

int ct = 0;

void encode(string input){

	if(input.size() == 0){
		ct++;
		return;
	}
	else{
		int val = atoi((input.substr(0,1)).c_str());
		if(val >= 1 && val <= 9){
			encode(input.substr(1));
		}
		if(input.size()>=2){
			int val1 = atoi(input.substr(0,1).c_str());
			int val2 = atoi(input.substr(1,1).c_str());
			if(val1 == 1 && (val2 >= 0 && val2 <= 9))
				encode(input.substr(2));
			else if(val1 == 2 && (val2 >= 0 && val2 <= 6))
				encode(input.substr(2));
		}
	}

} 

int main(int argc,char* argv[]){
	cout<<endl;
	encode(string(argv[1]));
	cout<<endl<<"Value:"<<ct;
	cout<<endl;
	return 0;
}
