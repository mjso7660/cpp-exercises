#include <iostream>
using namespace std;

//countSort. 
//Lessons Learned:
//1. .size() for array is for stl type ::array. no .size() native array type. 
//2. Setting up an array doesn't necessary set its elements to zero. Should be done manually.

int* countSort(int *A, int* B, int leng, int k){
	int C[k+1];
	for(auto &x:C)
		x=0;
	for(int j=0;j!=leng;++j){
		C[A[j]]=C[A[j]]+1;
	}
	for(int i=0; i!=k+1; ++i){
		C[i+1]=C[i+1]+C[i];
	}
	for(int j=leng-1;j!=-1;--j){
		B[C[A[j]]-1]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	
	return B;

}

int main(){
	int k, element=0;
	int leng;
	cout<<"type max range:"<<endl;
	cin>>k;	//max range
	cout<<"type length of the array:"<<endl;
	cin>>leng;	//array length
	int array[leng];
	for(auto &x:array)
		x=0;
	int newArray[leng];
	for(auto &x:newArray)
		x=0;
	cout<<"type array elemnts"<<endl;
	for(int i=0; i!=leng; ++i){
		cin>>element;
		array[i]=element;
	}

	*newArray=*countSort(array, newArray, leng, k);
	for(auto &x:newArray)
		cout<<x<<" ";


}
