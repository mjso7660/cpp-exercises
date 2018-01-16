#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

//Longest Increasing Subsequence of an array[], using Dynamic Programming
//Prints out what the elements of the LIS is and the length
int lis(int *A, int n){
	int B[n], C[n];
	for(auto &x:C)
		x=1;
	for(int i=0;i!=n;i++)
		B[i]=i;
	

	for(int i=n-1;i!=-1;--i)
		for(int j=n-1;j!=i-1;--j)
			if((A)[j]>(A)[i] && C[j]>=C[i]){
				C[i]=C[j]+1;
				B[i]=j;
			}
	int max=1;
	for(auto &x:C)
		if(x>max)
			max=x;
	for(int j=0;j!=n;++j){
		int i=j;
		if(C[i]==max){
			while(B[i]!=i){
				cout<<A[i]<<" ";
				i=B[i];
			}
			cout<<A[i]<<endl;
		}
	}
	return max;
}

int main(){
	int array[]={10, 22, 9, 23, 15, 1, 2,3, 24, 11};
	cout<<"Max length is: "<<lis(array,10);
}
