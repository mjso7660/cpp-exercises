#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include "chapter6.h"
#include <cassert>
using namespace std;


int main(int argc, char *argv[])
{
	srand(time(NULL));
	int arry[10];
	int i=0;
	for(auto beg=begin(arry);beg!=end(arry);beg++){
		auto beg2=begin(arry);
		int i=rand()%10;
		while(beg2!=end(arry)-1){
			if(i==*beg2){
			i=rand()%10;
				beg2=begin(arry);
			}else{
			++beg2;	
			}
		}
		*beg=i;
	}
	for(int j:arry){
		cout<<j<<" ";
	}
	return 0;
}

