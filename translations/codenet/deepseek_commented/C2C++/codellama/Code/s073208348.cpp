#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

//辺の情報を個別に持つタイプ
struct edge{ll s,g,c;}; // Define the structure for edges
struct graph{
	int vcnt,ecnt;
	edge  e[200010];//適宜変える // Define the array of edges
	int id[100010];//適宜変える // Define the array of indices
}; // Define the structure for the graph

bool esort(const edge&a,const edge&b){ // Define a function to sort edges
	if(a.s<b.s)return true; // Compare edges based on start vertex
	if(a.s>b.s)return false;
	if(a.g<b.g)return true; // Compare edges based on end vertex
	return false;
}

graph g; // Define a global graph variable
void readgraph(){ // Define a function to read the graph
	//適宜変える
	ll n;
	cin>>n; // Read the number of vertices
	rep(i,0,n-1){ // Read each edge and store it in the graph structure
		ll x,y,c;
		cin>>x>>y>>c;
		g.e[2*i].s=x;
		g.e[2*i].g=y;
		g.e[2*i].c=c;
		g.e[2*i+1].s=y;
		g.e[2*i+1].g=x;
		g.e[2*i+1].c=c;
	}
	g.vcnt=n; // Set the number of vertices
	g.ecnt=2*n-2; // Set the number of edges
	sort(g.e,g.e+g.ecnt,esort); // Sort the edges

	int p=0;
	rep(i,0,g.vcnt){ // Populate the id array with the starting index of edges for each vertex
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵 // Set the sentinel value for the id array
}

//木の直径を求める2回dfs
//*
int*tyokkeitemp; // Define a temporary array for DFS
void tyokkeidfs(ll s){ // Define a function to perform DFS and update distances
	for(int i=g.id[s];i<g.id[s+1];i++){
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
			tyokkeidfs(g.e[i].g);
		}
	}
}
int tyokkei(){ // Define a function to find the diameter of the tree
	tyokkeitemp=(int*)calloc(g.vcnt+10,sizeof(int)); // Allocate memory for the temporary array
	tyokkeitemp[0]=1; // Start DFS from the root
	tyokkeidfs(0); // Perform DFS
	int M=0,Mi; // Initialize variables to find the maximum distance
	rep(i,0,g.vcnt){ // Find the vertex with the maximum distance from the root
		if(tyokkeitemp[i]>M){
			M=tyokkeitemp[i];
			Mi=i;
		}
	}
	rep(i,0,g.vcnt)tyokkeitemp[i]=0; // Reset the temporary array
	tyokkeitemp[Mi]=1; // Start DFS from the farthest vertex found
	tyokkeidfs(Mi); // Perform DFS
	rep(i,0,g.vcnt)M=max(M,tyokkeitemp[i]); // Find the maximum distance in the second DFS
	free(tyokkeitemp); // Free the allocated memory
	return M-1; // Return the diameter of the tree
}
//*/

int main(){ // Define the main function
	readgraph(); // Read the graph
	cout<<tyokkei()<<endl; // Print the diameter of the tree
}

