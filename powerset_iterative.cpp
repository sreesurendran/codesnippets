//print all subsets of a given set (iterative)
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void powerSet(vector<string> originalSet){
	cout<<endl;
	int powerSetSize = pow(2,originalSet.size());
	for(int counter = 0; counter < powerSetSize; counter++){
		if(counter == 0)
			cout<<"{},";
		for(int j = 0; j<originalSet.size(); j++){
			if((counter >> j) & 1 == 1)
				cout<<originalSet[j]<<",";
		}
		cout<<endl;
	}
	return;
}

int main(){
		
	vector<string> arr = {"1","2","3"};
	powerSet(arr);	
	cout<<endl;
	return 0;
}
