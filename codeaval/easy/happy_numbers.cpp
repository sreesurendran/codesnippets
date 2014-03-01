/*

A happy number is defined by the following process. Starting with any positive
integer, replace the number by the sum of the squares of its digits, and
repeat the process until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1. Those numbers for which this
process ends in 1 are happy numbers, while those that do not end in 1 are
unhappy numbers.

Sample invocation:

./a.out 19
	Expected output:Happy

*/


#include <iostream>
#include <cmath>

using namespace std;

bool isHappy(int num){
	
	int result = 0;
	int orig = num;

	while(num > 0){
		result = result + pow(num%10,2);
		num = num / 10;
		if(num == 0){
			if(result == 1)
				return true;
			else if(result == orig)
				return false;
			else{
				num = result;
				result = 0;
			}
		}
	}
}

int main(int argc,char* argv[]){

	cout<<endl;
	if(argc < 2){
		cout<<endl<<"Enter number"<<endl;
		return 0;
	}
	else{
		bool check = isHappy(atoi(argv[1]));
		if(check)
			cout<<endl<<"Happy";
		else
			cout<<endl<<"Sad";
	}

	cout<<endl;
	return 0;
}
