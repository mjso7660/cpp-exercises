#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

//BellmandFord implementation
//prints out distance from the source to each vertext ONLY IF there it doesn't contain a negative weight cycle

//sets infinity to the greates integer a byte can hold
int infinity=numeric_limits<int>::max();

class Edge{
	public:
	int dest;	//index of the destination
	int weight;
};

class Graph{
	public:
	int V=0;	//initializes # of vertices to zero
	int E=0;	//initializes # of edges to zero
	vector<vector<Edge>> adjList;	//adjList[u] contains a vector of all adjacent vertices

	void addVert();
	void addEdge(int, int, int);
};


void Graph::addVert(){
	vector<Edge> newVertex;
	adjList.push_back(newVertex);
	++V;
}

//create edge from 'u' to 'v' with a weight
void Graph::addEdge(int u, int v, int weight){	
	Edge newEdge;
	newEdge.dest=v;
	newEdge.weight=weight;
	adjList[u].push_back(newEdge);
	++E;
}

//algorithm computes min distance from the source 's'. 
//Can pass in 'false' as a third argument to find the maximum instead
void bellmanFord(Graph* graph, int s, bool min=true){
	int abs=1;	
	if(!min){
		abs*=-1;	//this turns all weights negative when finding max
	}
	int V=graph->V;
	int E=graph->E;
	int dist[V];		//stores distance from 's'

	for(int i=0; i!=V; ++i){
		dist[i]=infinity;	//initializes distance to inifinty
	}
	dist[s]=0;		//initial condition

	//bottom up dynamic programming
	for(int i=1;i!=V;++i){	//all vertices	
		for(int j=0;j!=E;++j){	//all edges
			auto leng=(*graph).adjList[j].size();
			for(int k=0;k!=leng;++k){
				int u=j;
				int v=graph->adjList[j][k].dest;
				int weight=(*graph).adjList[j][k].weight;
				weight*=abs;	//negate if finding the max
				if(dist[u]!=infinity && dist[v]>(dist[u]+weight)){
					dist[v]=dist[u]+weight;		//re
				}
			}
		}
	}

	//this checks for infinite negative loops
	for(int j=0;j!=E;++j){		
		auto leng=(*graph).adjList[j].size();
		for(int k=0;k!=leng;++k){
			int u=j;
			int v=graph->adjList[j][k].dest;
				int weight=(*graph).adjList[j][k].weight;
				weight*=abs;
				if(dist[u]!=infinity && dist[v]>(dist[u]+weight)){
					cout<<"Graph contains negative weight cycle"<<endl;
					return;
				}
		}
	}
	for(auto &x:dist)
		cout<<endl<<abs*x<<" ";
}

//finding the max
void bellmanFordMax(Graph* graph, int s){
	bellmanFord(graph, s, false);
}

int main(){
	Graph graph;
	Graph* ptr=&graph;
	graph.addVert();
	graph.addVert();
	graph.addVert();
	graph.addVert();
	graph.addVert();
	graph.addEdge(0,1,2);
	graph.addEdge(0,3,2);
	graph.addEdge(1,2,-4);
	graph.addEdge(3,1,3);
	graph.addEdge(3,4,1);
	graph.addEdge(4,1,1);
	graph.addEdge(4,2,2);
	bellmanFord(ptr,0);
	bellmanFordMax(ptr, 0);
}	
