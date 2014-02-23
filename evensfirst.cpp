#include <iostream>

using namespace std;

void evens_first(int* array, int length){

	int even_ctr = length - 1;
	for(int odd_ctr = 0;odd_ctr<even_ctr;odd_ctr++){
		if(array[odd_ctr] % 2 != 0){
			while(even_ctr >= 0 && array[even_ctr] % 2 != 0){
				even_ctr--;
			}
			if(even_ctr >= odd_ctr){
				swap(array[even_ctr],array[odd_ctr]);
				even_ctr--;
			}
		}
	}
}

int main(){

	int array[] = {1,3,5,2,4,6,7,9,12};
	int length = 9;
	evens_first(array,length);
	cout<<endl<<"After function call:"<<endl;
	for(int i=0;i<length;i++){
		cout<<array[i]<<endl;
	}
	cout<<endl;
	return 0;
}
