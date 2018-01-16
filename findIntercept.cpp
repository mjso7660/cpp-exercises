#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include "chapter6.h"
#include <cassert>
using namespace std;

//finding the f(x)=0

double f(double x){
	return x*x-x;
}

double find(double f(double),double low, double high){
	double mid=(high+low)/2;
	if(f(mid)*f(low)<0){
		if(abs(f(mid)-f(low))<0.01){
			return mid;
		}else{
			return find(f,low,mid);
		}
	}else if(f(mid)*f(high)<0){
		if(abs(f(mid)-f(high))<0.01){
			return mid;
		}else{
			return find(f,mid,high);
		}
	}else{
		return 255;
	}
}
				

int main(int argc, char *argv[])
{
	cout<<find(f,-10000,1000000.00);
	return 0;
}

