#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <array>
//#include "person.h"
#include <cassert>
using namespace std;

//mergeSort(working), running time n*log(n)
int merge(auto *A, int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	vector<int> left;
	vector<int> right;
	for(int i=0;i!=n1;i++){
		left.push_back(A[p+i]);
	}	
	for(int i=1;i!=n2+1;i++){
		right.push_back(A[q+i]);
	}
	int a=0; int b=0;
	int k=p;
	while((a!=n1)&&(b!=n2)){
		if(left[a]<=right[b]){
			A[k]=left[a];
			++a;
		}else if(left[a]>right[b]){
			A[k]=right[b];
			++b;
		}else{
			cout<<"ERROR"<<endl;
			return -1;
		}
		++k;
	}
	if(a==n1){
		for(int m=b;m!=n2;m++){
			A[k]=right[m];
			++k;
		}
	}
	if(b==n2){
		for(int m=a;m!=n1;m++){
			A[k]=left[m];
			++k;
		}
	}
}
int merge_sort(auto *A,int p, int r){
	if(p<r){
		int q=(r+p)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}
int main(int argc, char *argv[])
{
	vector<int> v1;
	int i;
	while(cin>>i){
		v1.push_back(i);
	}
	int sz=v1.size();
	merge_sort(&(v1[0]),0,sz-1);
	for(int i:v1){
		cout<<i<<" ";
	}	
}
