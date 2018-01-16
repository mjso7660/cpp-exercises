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

int main(int argc, char *argv[])
{
	vector<int> v1;
	int i;
	while(cin>>i){
		v1.push_back(i);
	}
	for(int j=1;j!=v1.size();j++){
		int key=v1[j];
		int k=j-1;
		while(k+1>0&&v1[k]>key){
			v1[k+1]=v1[k];
			--k;
		}
		v1[k+1]=key;
	}
	for(int i=0;i!=v1.size();i++){
		cout<<v1[i];
	}

}



