#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

//Dynamic Programming: Set 6 from "GeeksforGeeks.org"
//Min Cost Path. Prints out the minimum cost reaching (x,y) from (0,0) and its path

//util function for finding the minimum among "i, j and k" and returns the min
//also changes val of *ptr to figure out where it came from: 1 - from left/ 2 - from diagonal/ 3- from top
int min(int i,int j, int k,int *ptr){
	int min=i;
	*ptr=3;
	if(min>j){
		min=j;
		*ptr=1;
	}
	if(min>k){
		min=k;
		*ptr=2;
	}
	return min;
}

int minCostPath(vector<vector<int>>* L,int n,int m){
	int inf=99999;
	int DP[n][m];	//saves the min cost
	int path[n][m];	//saves the min path
	int foo;
	int *ptr=&foo;

	//initializes min cost to infinity and min path to -1 (NULL)
	for(int i=0;i!=n;++i)
		for(int j=0;j!=m;++j){
			DP[i][j]=inf;
			path[i][j]=-1;
		}

	//Dynamic programming portion: bottom-up approach 
	for(int i=0;i!=n;++i){
		for(int j=0;j!=m;++j){
			if(i==0&&j==0){
				DP[0][0]=(*L)[0][0];
			}else if(i==0&&j!=0){
				DP[0][j]=DP[0][j-1]+(*L)[0][j];
				path[0][j]=1;
			}else if(j==0&&i!=0){
				DP[i][0]=DP[i-1][j]+(*L)[i][0];
				path[i][0]=3;
			}else if(DP[i][j]>min(DP[i-1][j],DP[i][j-1],DP[i-1][j-1],ptr)+(*L)[i][j]){
				DP[i][j]=min(DP[i-1][j],DP[i][j-1],DP[i-1][j-1],ptr)+(*L)[i][j];
				path[i][j]=*ptr;
			}
		}
	}

	//printing the min path
	int i=2, j=2;
	while(path[i][j]!=-1){
		int k=path[i][j];
		cout<<(*L)[i][j]<<"->";
		if(k==1){
			j-=1;
		}else if(k==2){
			j-=1;
			i-=1;
		}else{
			i-=1;
		}
	}
	cout<<(*L)[i][j]<<endl;

	return DP[2][2]; 
}
			


int main(){
	vector<vector<int>> array={{1,2,3},{4,8,2},{1,5,3}};
	cout<<minCostPath(&array,3,3);

}
