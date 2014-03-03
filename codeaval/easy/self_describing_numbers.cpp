/*

# A number is a self-describing number when (assuming digit positions are
# labeled 0 to N-1), the digit in each position is equal to the number of times
# that that digit appears in the number.

*/

#include <iostream>
#include <unordered_map>

using namespace std;

bool isSelfDescribing(string input){

	bool isSelf = true;
        unordered_map<char,int> count;
        for(int i=0;i<input.size();i++){
        	if(count.find(input[i]) != count.end()){
                	int val = count.at(input[i]);
                        count.at(input[i]) = ++val;
                }
                else{
                	count.insert(make_pair(input[i],1));
                }
	}
        for(int i=0;i<input.size();i++){
        	if(i%2==0 && i<= input.size()-2){
			string temp(1,input[i]);
                	int temp_val = atoi(temp.c_str());
                        int val;
                        if(count.find(input[i+1]) != count.end()){
                        	val = count.at(input[i+1]);
                        }
                        if(temp_val != val){
                        	isSelf = false;
                                break;
                        }
                }
        }
	return isSelf;
}

int main(int argc, char* argv[]){

	if(argc < 2){
		cout<<endl<<"Enter number"<<endl;
		return 0;
	}
	else{
		cout<<endl;
		string input(argv[1]);
		if(input.size() % 2 != 0){
			cout<<endl<<"Odd number of digits"<<endl;
			return 0;
		}
		if(isSelfDescribing(input))
			cout<<endl<<"Self Describing Number";
		else
			cout<<endl<<"Not Self Describing Number";
	}

	cout<<endl;
	return 0;
}
