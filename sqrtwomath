#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

	float num;
	cout<<endl<<"Enter number: ";
	cin>>num;

	float root = 0;

	float lb = 0;
	float ub = num;
	float mid = (lb+ub)/2;

	
	while(true){
		float x = mid * mid;
		x = roundf(x*100)/100;
		if(x - num == 0.01 || num - x == 0.01 || x==num){
			root = mid;
			break;
		}
		else if(x > num){
			ub = mid-1;
		}
		else if(x<num){
			lb = mid+1;
		}
		mid = (lb+ub)/2;
	}

	cout<<endl<<"Square root: "<<setprecision(3)<<root;	



	cout<<endl;
	return 0;
}
