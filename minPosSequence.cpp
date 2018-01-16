#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include "chapter6.h"
#include <cassert>
using namespace std;

//finding the minium positive subsequence sum in an arry

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int arry[10]={-4,3,7,-2,-11,5,6,-1,5,10};
	int max=0;
	int sum=0;
	for(auto beg=begin(arry);beg!=end(arry);++beg){
		int temp=*beg;
		for(auto beg2=(beg+1);beg2!=end(arry);++beg2){
			temp+=*beg2;
			if(temp>0&&(temp<max||max==0)){
				max=temp;
			}
		}
	}
	cout<<max;
	return 0;
}

