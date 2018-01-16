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

//finds the majority of an array of people's names
int candidate(vector<int> arry){
	vector<int> arry2={};
	int odd=0;
	if((arry.end()-arry.begin())%2==1){
		odd=1;
	}
	for(auto p=arry.begin();p<(arry.end()-odd);p+=2){
       	         if(*p==*(p+1)){
       	                 arry2.push_back(*p);
       	         }
	}
	if((arry2.end()-arry2.begin())==1){
		return arry2[0];
	}else if(arry2.end()==arry2.begin()){
		if(odd){
			return *(arry.end()-1);
		}else{
			return 0;
		}
	}else{
		return candidate(arry2);
	}
}

//find prime
int main(int argc, char *argv[])
{
	vector<int> v1={};
	int k;
	while(cin>>k){
		v1.push_back(k);
	}
	int maj=candidate(v1);
	int cnt=0;
	for(int i:v1){
		if(i==maj){
			++cnt;
		}
	}
	if(cnt>((v1.end()-v1.begin())/2)){
		cout<<maj;
	}
}


