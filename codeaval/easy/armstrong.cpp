/* 
An Armstrong number is an n-digit number that is equal to the sum of the n'th
powers of its digits. Determine if the input numbers are Armstrong numbers.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){

	if(argc < 2){
		cout<<endl<<"Enter number"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		int num = atoi(argv[1]);
		int n = string(argv[1]).size();
		int result;

		while(num > 0){
			result = result + pow(num%10,n);	
			num = num / 10;
		}

		if(to_string(result) == string(argv[1]))
			cout<<endl<<"Armstrong Number";
		else
			cout<<endl<<"Not an armstrong number";

	}
	cout<<endl;
	return 0;
}
