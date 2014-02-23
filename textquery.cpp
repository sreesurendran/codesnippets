/*

Problem:

TextQueryProblem
Write a program that takes two strings as input, one is a query, and the other is a string that may or may not contain that query. The program needs to find if the query is contained within the body string. 

Details:

0) The query should only match the body text if it matches the start of a word within the body text. 
1) That is, the beginning of the query must also be the start of a word within the body text. For example, the query "cat" would match the strings "cat", "cat toy", "this is a cat", and "catty". However, the query "cat" would not match the string "location". 
2) The program should  be case insensitive. 
3) The program needs to be able to match queries without spaces in them, even if the body does have spaces. For example, the string "Luke Johnston" would be matched by the query "luke j" and the query "lukej". 
4) However, this does not work the other way around. The query "luke j" should not match the string "lukejohnston". 
5) The input text file will have  the first line containing an integer corresponding to the number of following problem input sets. Each following pair of lines will contain the query string on the first line, followed by the body string on the second line. Thus, if the first line contains the number 10, there are 20 more lines in the file. 
6) The answers should be output to a text file with the first line containing an integer corresponding to the number of following individual answers. Each following line will contain a 1 if a match was found, or a 0 if a match was not found. 

sample command line invocation: ./a.out SampleInput_TQM.txt

//todo: move code from main() to a separate function.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> splitStringByDelimiter(string str,char delim){
        vector<string> vecTemp;
        istringstream partialString(str);
        string tempPartialLine;
        while(getline(partialString,tempPartialLine,delim)){
                vecTemp.push_back(tempPartialLine);
        }
        return vecTemp;
}

int main(int argc,char* argv[]){
	

	if(argc < 2){
		cout<<endl<<"Provide input:";
		return 0;
	}
	else{
		string probSetSize;
		int ct = 0;
		int pairCt = 0;
		bool isQuery = true;;
		vector<string> pairs;
		string line;
		ifstream infile(argv[1]);
		string input;
		if(infile.is_open()){
			while(getline(infile,line)){
				ct++;
				if(ct == 1){
					probSetSize = line;
				}
				else{
					if(isQuery){
						input = line;
						isQuery = false;
					}
					else{
						input += ";" + line;
						isQuery = true;
						pairs.push_back(input);
						pairCt++;
						input = "";
					}
				}
			}
			infile.close();
		}
		
		vector<string> output;
		for(int i=0;i<pairs.size();i++){
			vector<string> values = splitStringByDelimiter(pairs[i],';');
			string queryUpper, bodyUpper;
        		transform(values[0].begin(),values[0].end(),back_inserter(queryUpper),::toupper);
			transform(values[1].begin(),values[1].end(),back_inserter(bodyUpper),::toupper);			       bool isMatch = false;
			size_t found = bodyUpper.find(queryUpper);
			if(found != string::npos){
				if(found == 0){
					output.push_back("1");
				}
				else{
					if(bodyUpper[found - 1] == ' ')
						output.push_back("1");
					else
						output.push_back("0");	 
				}	
			}
			else{
					int j=0;	
					for(int k=0;k<bodyUpper.size();k++){
						if(queryUpper[j] != bodyUpper[k])
							continue;
						else{
							while(j<queryUpper.size()){
								if(queryUpper[j] != bodyUpper[k]){
									if(bodyUpper[k] == ' '){
										k++;
										continue;
									}
									else{
										j = 0;
										break;
									}
								}
								else{
									j++;
									k++;
								}
								if(j == queryUpper.size() - 1)
									isMatch = true;
							} 
						}
					}
					if(isMatch)
						output.push_back("1");
					else
						output.push_back("0");
					isMatch = false;
			}

	
		}

		ofstream outfile("textquery_out.txt");
		outfile<<output.size()<<endl;
		for(int i=0;i<output.size();i++){
			outfile<<output[i]<<endl;
		}
		outfile.close();
	
	}



	cout<<endl;
	return 0;

}
