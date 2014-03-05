/*
A double-square number is an integer X which can be expressed as the sum of two perfect squares. For example, 10 is a double-square because 10 = 3^2 + 1^2. Your task in this problem is, given X, determine the number of ways in which it can be written as the sum of two squares. For example, 10 can only be written as 3^2 + 1^2 (we don't count 1^2 + 3^2 as being different). On the other hand, 25 can be written as 5^2 + 0^2 or as 4^2 + 3^2. 
NOTE: Do NOT attempt a brute force approach. It will not work. The following constraints hold: 
0 <= X <= 2147483647
1 <= N <= 100

https://github.com/xisisu/CodeEval/blob/master/Moderate/DoubleSquares.cc

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getNbWays(long long x){

	int count = 0;
	set<long long> table;
	table.insert(0);

	auto t = table.end();
	t--;

	while(*t < x){
		long long cur = table.size() * table.size();
		table.insert(cur);
		t = table.end();
		t--;
	}

	for(auto ii=table.begin();ii!=table.end();ii++){
		if(*ii > x/2)
			break;
		if(table.find(x-*ii) != table.end())
			count++;
	}

	return count;
}

int main(int argc, char* argv[]){

	if(argc == 1){
		cout<<endl<<"Enter number"<<endl;
		return 0;
	}
	else{
		cout<<endl<<"Number of ways:"<<getNbWays(atoll(argv[1]));
		cout<<endl;
		return 0;
	}
}


