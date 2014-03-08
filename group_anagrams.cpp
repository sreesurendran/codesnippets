#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	
	if(argc == 1){
		cout<<endl<<"Enter input strings"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		vector<string> params;
		//to avoid ./a.out to be processed
		for(int i=1;i<argc;i++)
			params.push_back(string(argv[i]));

		//build map
		unordered_map<string,vector<string>> anagramsMap;
		for(int i=0;i<params.size();i++){
			string sorted = params[i];
			std::sort(sorted.begin(),sorted.end());
			if(anagramsMap.find(sorted) != anagramsMap.end()){
				vector<string> temp = anagramsMap.at(sorted);
				temp.push_back(params[i]);
				anagramsMap.at(sorted) = temp;
			}
			else{
				vector<string> temp = {params[i]};
				anagramsMap.insert(make_pair(sorted,temp));
			}
		}
		
		//print map
		cout<<endl<<"Grouping"<<endl<<endl;
		for(auto ii=anagramsMap.begin();ii!=anagramsMap.end();ii++){
			vector<string> temp = ii->second;
			const char* prefix = "";
			for(int i=0;i<temp.size();i++){
				cout<<prefix<<temp[i];
				prefix = ",";
			}
			cout<<endl;
		}
		cout<<endl;
		return 0;
	}
	

}
