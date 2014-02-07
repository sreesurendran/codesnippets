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
	/*
        for(unordered_map<string,int>::iterator it=htabTemp.begin();it!=htabTemp.end();it++){
                cout<<endl<<"Key: "<<it->first<<","<<"Value: "<<it->second;
        }
	*/

     	for(int i=2;i<params.size();i++){
                //find current element in the hashtable
                //cout<<endl<<"Here1";
		if(htabTemp.find(params[i]) != htabTemp.end()){
                        //if found, check if the value is not 0
			//cout<<endl<<"Here2";
                        if(htabTemp[params[i]] != 0){
				//cout<<endl<<"Here3";
                                int val = htabTemp[params[i]];
                                htabTemp[params[i]] = --val;
                                string key = to_string(k - atoi(params[i].c_str()));
                                //find if the complement for the current element exists in the hastable
                                if(htabTemp.find(key) != htabTemp.end()){
					//cout<<endl<<"Here4";
                                        //if found, check if the value is not 0
                                        if(htabTemp[key] != 0){
						//cout<<endl<<"Here5";
                                                //loop through and print
						for(int j=0;j<htabTemp[key];j++){
							output += params[i] + "," + key + ";";
							//cout<<endl<<"ValueInner:"<<output;
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
	//params(argv,argv+argc);
	//unordered_map<string,int> htabElem;
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
		vector<string> pairs;
		if(htabElem.find(params[i]) != htabElem.end()){
			if(htabElem[params[i]] != 0){
				int val = htabElem[params[i]];
				htabElem[params[i]] = --val;
				string output = findSum(k-atoi(params[i].c_str()));
				//cout<<endl<<"Output:"<<output;
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
