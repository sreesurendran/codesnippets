//For an unosrted array, given a value k, list all the pairs of numbers that sum upto k
//No duplicates
//Complexity: O(n)
//I/P format: ./a.out <k> <array_separated_by_single_space>
//eg.: ./a.out 6 3 7 1 2 3 4 5 1 -1 7 3

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc,char* argv[]){

	//0th element in argv is ./a.out
	//1st element in argv is k	

	//declare variables
	vector<string> params(argv,argv+argc);
	unordered_map<string,int> htabElem;
	int k=atoi(params[1].c_str());
	
	//construct hashtable
	for(int i=2;i<params.size();i++){
		if(htabElem.find(params[i]) != htabElem.end()){
			int val = htabElem[params[i]];
			htabElem[params[i]] = ++val;
		}
		else
			htabElem[params[i]] = 1;			
	}
	
	/*
	//print the hashtable
	for(unordered_map<string,int>::iterator it=htabElem.begin();it!=htabElem.end();it++){
		cout<<endl<<"Key: "<<it->first<<","<<"Value: "<<it->second;
	}
	*/
	
	cout<<endl<<"The array sum pairs are:";
	
	for(int i=2;i<params.size();i++){
		//find current element in the hashtable
		if(htabElem.find(params[i]) != htabElem.end()){
			//if found, check if the value is not 0
			if(htabElem[params[i]] != 0){
				int val = htabElem[params[i]];
				htabElem[params[i]] = --val;
				string key = to_string(k - atoi(params[i].c_str()));
				//find if the complement for the current element exists in the hastable
				if(htabElem.find(key) != htabElem.end()){
					//if found, check if the value is not 0
					if(htabElem[key] != 0){
						//print the pair
						for(int j=0;j<htabElem[key];j++){
							cout<<endl<<"("<<params[i]<<","<<key<<")";	
						}
					}
				}
			}
		}
	}

	cout<<endl;
	return 0;
}
