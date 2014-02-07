//For an unosrted array, given a value k, list all the triplets of numbers that sum upto k
//No duplicates
//Complexity: O(n^2)
//I/P format: ./a.out <k> <array_separated_by_single_space>
//eg.: ./a.out 6 3 7 1 2 3 4 5 1 -1 7 3

//O/P:
//3 - 3,2;1,4;2,3;4,1;
//7 - 2,-1;
//1 - 3,4;2,5;3,4;
//2 - 3,3;7,-1;1,5;
//3 - 1,4;
//4 - 3,1;5,-1;

//indicates 3,3,2; 3,1,4; 3,2,3; 3,4,1;
//and so on

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

vector<string> params;
unordered_map<string,int> htabElem;

string findSum(int k){

	string output = "";
	unordered_map<string,int> htabTemp = htabElem;

     	for(int i=2;i<params.size();i++){
                //find current element in the hashtable
		if(htabTemp.find(params[i]) != htabTemp.end()){
                        //if found, check if the value is not 0
                        if(htabTemp[params[i]] != 0){
                                int val = htabTemp[params[i]];
                                htabTemp[params[i]] = --val;
                                string key = to_string(k - atoi(params[i].c_str()));
                                //find if the complement for the current element exists in the hastable
                                if(htabTemp.find(key) != htabTemp.end()){
                                        //if found, check if the value is not 0
                                        if(htabTemp[key] != 0){
                                                //loop through and print
						for(int j=0;j<htabTemp[key];j++){
							output += params[i] + "," + key + ";";
						}
                                        }
                                }
                        }
                }
        }

	return output;

}


int main(int argc,char* argv[]){

	//0th element in argv is ./a.out
	//1st element in argv is k	

	//declare variables
	for(int i=0;i<argc;i++){
		params.push_back(argv[i]);
		//cout<<"Value: "<<params[i];
	}
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
	
	cout<<endl<<"The array sum triplets are:";

	for(int i=2;i<params.size();i++){
		vector<string> pairs;
		if(htabElem.find(params[i]) != htabElem.end()){
			if(htabElem[params[i]] != 0){
				int val = htabElem[params[i]];
				htabElem[params[i]] = --val;
				string output = findSum(k-atoi(params[i].c_str()));
				if(output != ""){
					cout<<endl<<params[i]<<" - ";
					cout<<output;
				}
			}	
		}
	}
	
	cout<<endl;
	return 0;
}
