#include <iostream>

using namespace std;

float pow(float base, float exp){

	if(exp>=1)
		return base * pow(base,exp-1);
	else
		return 1;
}

int main(){

	float base,exp;
	cin>>base;
	cin>>exp;
	float ans;
	if(exp<0){
		exp = -exp;
		ans = 1/pow(base,exp);
	}
	else
		ans = pow(base,exp);
	cout<<endl<<"Ans: "<<ans<<endl;
	return 0;

}
