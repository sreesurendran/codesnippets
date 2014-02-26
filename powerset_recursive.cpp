//print all subsets of a given set (recursive)
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> powerSet(vector<string> originalSet){
	vector<vector<string>> sets;
	//base case
	if(originalSet.size() == 0){
		vector<string> nullSet;
		sets.push_back(nullSet);
		return sets;
	}
	//remove first element from the vector
	string head = originalSet[0];
	vector<string> rest;
	//copy elements from position 1 to the end of the originalSet to rest
	for(int i=1;i<originalSet.size();i++){
		rest.push_back(originalSet[i]);
	}
	//recursion used here
	for(vector<string> set:powerSet(rest)){
		vector<string> newSet;
		newSet.push_back(head);
		for(int k=0;k<set.size();k++)
			newSet.push_back(set[k]);
		//union
		sets.push_back(newSet);
		sets.push_back(set);
	}
	return sets;
}

int main(){

	vector<string> arr = {"1","2","3","4","5"};
	vector<vector<string>> pSet = powerSet(arr);
	for(int i=0;i<pSet.size();i++){
		if(pSet[i].size() == 0){
			cout<<"{},";
		}
		for(int j=0;j<pSet[i].size();j++){
			cout<<pSet[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
