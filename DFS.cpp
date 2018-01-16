#include<iostream>
#include<list>
#include<map>
#include<iterator>
#include<utility>
#include<string>
#include<vector>
using namespace std;

//Depth First Search. Prints the order of vertices visited. 
//Sort by number of results->finishTime to Topological-sort
class DFSResult{
	int V;
public:
	vector<int>* parent;
	vector<int>* startTime;
	vector<int>* finishTime;
	vector<int>* edges;
	vector<int>* order;
	DFSResult(int);
	int t=0;
};

DFSResult::DFSResult(int V){
	this->V=V;
	parent = new vector<int> (V);
	startTime= new vector<int> (V);
	finishTime= new vector<int> (V);
	edges= new vector<int> (V);
	order= new vector<int>;
}

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;
    void DFSUtil(int v, DFSResult*);
    
    public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void DFS(int v,map<string,int>&);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, DFSResult *results){
    (*results->parent)[v]=true;
    results->t+=1;
    (*results->startTime)[v]=results->t;

    list<int>::iterator it2;
    for (it2 = adj[v].begin(); it2 != adj[v].end(); ++it2){
        if (!((*results->parent)[*it2]))
            DFSUtil(*it2, results);
    }
    results->t +=1;
    (*results->finishTime)[v]=results->t;
    (*results->order).push_back(v);
}
 
void Graph::DFS(int v, map<string,int>& hash)
{
    DFSResult *results=new DFSResult(V);
    DFSUtil(v, results);

    //hash matching
    int len=end(*results->order)-begin(*results->order);
    for(int j=0;j!=len;++j){
	    map<string,int>::iterator it;
	    for(it=begin(hash);it!=end(hash);it++){
		    if((*results->order)[j]==it->second){
			    cout<<it->first<<" ";
		    }
	    }
    }
}

// input structure: V(x) #V V1 #adj(V) V1 adj(V)...
// ex: a 3 a 2 b c b 1 c c 0 
int main(){
	map <string, int> hash;
	string root;
	int counter=0;
	int num, adNum, u, v, adjNum;

	cin>>root>>num;
	Graph g(num);
	for(int i=0;i!=num;++i){
		string key;
		cin>>key;
		if(hash.count(key)<=0){
			hash.emplace(make_pair(string(key),int(counter)));
			u=counter;
			++counter;
		}else{
			u=hash[key];
		}
		cin>>adjNum;
		for(int j=0;j!=adjNum;++j){
			string key2;
			cin>>key2;
			if(hash.count(key2)<=0){
				hash.emplace(make_pair(string(key2),int(counter)));
				v=counter;
				++counter;
			}else{
				v=hash[key];
			}
			g.addEdge(u,hash.find(key2)->second);
		}
	}
	g.DFS(hash[root],hash);
}
