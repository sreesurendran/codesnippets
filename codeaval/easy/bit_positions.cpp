/*

Given a number and two integers p1 and p2, 
check if bits in positions p1 and p2 are the same.
p1 and p2 are 1-based indices.

Sample command-line invocation:
./a.out 22 3 2
	Expected output:Bit positions are the same

*/

#include <iostream>

using namespace std;

bool isBitPosition(int num, int p1, int p2){

	//p1-1 and p2-1 since the bit positions are 1-based
	//if the bit positions are 0-based, then
	//compare ((num >> p1) & 1) and ((num >> p2) & 1)
	if(((num >> (p1-1)) & 1) == ((num >> (p2-1)) & 1))
        	return true;
        else
		return false;
}

int main(int argc,char* argv[]){

	cout<<endl;
	if(argc < 4){
		cout<<endl<<"Enter all inputs"<<endl;
		return 0;
	}
	else{
		int num = atoi(argv[1]);
		int p1 = atoi(argv[2]);
		int p2 = atoi(argv[3]);
		
		bool isBit = isBitPosition(num,p1,p2);
		if(isBit)
			cout<<endl<<"Bit positions are the same";
		else
			cout<<endl<<"Bit positions are different";

	}
	cout<<endl;
	return 0;

}
