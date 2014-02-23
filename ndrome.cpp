/*

Problem:

NDrome
Determine if input phrases are an 'N-Drome'. 

Details:

0) An N-Drome is a string that is the same forwards and backwards when split into n-character units. 
1) For example, a string would be a 1-drome if and only if it were a standard palindrome. 
2) An example of a 2-drome would be abcdab since its 2-character units are ab, cd, and ab, and its first and last 2-character units are identical. 
3) The program should indicate whether or not a given string is a valid N-Drome. 
4) Each input line consists of a string to evaluate, followed by a pipe character (|), and the N to use in the evaluation.  
6) The output file must contain the input information followed by an additional pipe character, and then a 1 or 0 to indicate that the input is or is not a valid N-Drome, respectively. 

sample invocation from command-line: ./a.out SampleInput.txt

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

bool isNDrome(string input, int n){
	if(n > input.size() || input.size()%n != 0){
		return false;
	}
	int parts = input.size() / n;
	for(int a=0, z=parts-1; a<z;a++,z--){
		string aSub = input.substr(a*n,n);
		string zSub = input.substr(z*n,n);
		if(aSub != zSub){
			return false;
		}
	}	
	return true;

}

vector<string> splitStringByDelimiter(string str,char delim){
	vector<string> vecTemp;
        istringstream partialString(str);
        string tempPartialLine;
        while(getline(partialString,tempPartialLine,delim)){
        	vecTemp.push_back(tempPartialLine);
        }
	return vecTemp;	
}


int main(int argc, char* argv[]){
	if(argc < 2){
		cout<<endl<<"Please specify an input file"<<endl;
		return 0;
	}
	cout<<endl;
	string line;
	ifstream infile(argv[1]);
	ofstream outfile("ndrome_out.txt");
	if(infile.is_open()){
		while(getline(infile,line)){
			vector<string> parts = splitStringByDelimiter(line,'|');
			bool isnd = isNDrome(parts[0],atoi(parts[1].c_str()));
			if(isnd)
				outfile<<parts[0]<<"|1"<<endl;
			else
				outfile<<parts[0]<<"|0"<<endl;
		}
		infile.close();
		outfile.close();
	}
	cout<<endl;
	return 0;
}
