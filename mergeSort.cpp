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

// ******DOESNT WORK PROPERLY*****//
//
//
//
//mergeSort, running time nlog(n)
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
	for(int i=0;i!=r-p+1;i++){
		if(left[a]<=right[b]){
			if((left[a])){
				A[p+i]=left[a];
				++a;
			}else{
				A[p+i]=right[b];
				++b;
			}
		}else{
			if((right[b])){
				A[p+i]=right[b];
				++b;
			}else{
				A[p+i]=left[a];
				++a;
			}
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
