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

//heapsort(working), running time n*log(n)

struct Heap{
	int heap_size;
	vector<int> p;
};

int maxheap(Heap &A,int i){
	int l=2*i;
	int r=2*i+1;
	int max;
	if(l<=A.heap_size&&A.p[l]>A.p[i]){
		max=l;
	}else{
		max=i;
	}
	if(r<=A.heap_size&&A.p[r]>A.p[max]){
		max=r;
	}
	if(max!=i){
		int temp=A.p[max];
		A.p[max]=A.p[i];
		A.p[i]=temp;
		maxheap(A,max);
	}
	return 0;
}

int build_max_heap(Heap &A){
	A.heap_size=A.p.size()-1;
	for(int i=(A.p.size()/2);i!=0;--i){
		maxheap(A,i);
	}
}

int main(int argc, char *argv[])
{
	int i;
	Heap B;
	Heap *A=&B;
	(*A).p.push_back(-1);
	while(cin>>i){
		(*A).p.push_back(i);
	}
	build_max_heap(*A);
	for(int i:(*A).p){
		if(i>=0){
			cout<<i<<" ";
		}
	}	
}
