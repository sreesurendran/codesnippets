/*

Given a string s, little Johnny defined the beauty of the string as the sum of
the beauty of the letters in it. The beauty of each letter is an integer
between 1 and 26, inclusive, and no two letters have the same beauty. Johnny
doesn't care about whether letters are uppercase or lowercase, so that doesn't
affect the beauty of a letter.

What is the maximum possible beauty of a string?

Solution:-

 The main idea is to count the frequency of each letter, then assign the value 26 
to the most frequent letter, 25 to the next, etc. If two letters are tied for most frequent, 
it doesn't matter which of them gets which value, since the sum will be the same. 

*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;



int main(int argc,char* argv[]){

	if(argc < 2){
		cout<<endl<<"Enter string"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		string input(argv[1]);
		unordered_map<string,int> frequency;
		multimap<int,string> count;

		for(int i=0;i<input.size();i++){
			//ensure that you're working with a letter
			if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')){
				string out;
				//convert char to string (useful, remember this)
				string in(1,input[i]);
				//convert case
				transform(in.begin(),in.end(),back_inserter(out),::tolower);
				//build and update the map
				if(frequency.find(out) != frequency.end()){
					int temp = frequency.at(out);
					frequency.at(out) = ++temp;
				}
				else
					frequency.insert(make_pair(out,1));
			}
		}

		//write map to a multimap
		//this needs to be done because unordered_mp (or map) cannot be sorted by value
		//multimaps can have duplicate keys and are sorted by keys (in ascending order)
		//for a <string,int> unordered_map, create an <int,string> multimap
		for(auto jj=frequency.begin();jj!=frequency.end();jj++){
			count.insert(make_pair(jj->second,jj->first));	
		}

		int beauty = 0;
		int add = 26;

		//use reverse_iterator to iterate backwards (in descending order)
		//i.e from most frequent characters to the least frequent ones
		for(auto ii=count.rbegin();ii!=count.rend();ii++){
			beauty = beauty + (ii->first * add);
			add--;
		}

		cout<<endl<<"Beauty:"<<beauty;
	}

	cout<<endl;
	return 0;
}


