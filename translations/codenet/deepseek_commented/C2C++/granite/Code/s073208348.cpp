
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

//辺の情報を個別に持つタイプ
typedef struct edge{ll s,g,c;}E; // Define the structure for edges
typedef struct graph{
	int vcnt,ecnt;
	std::vector<E> e; // Define a vector to store edges
	std::vector<int> id; // Define a vector to store indices
}G; // Define the structure for the graph

bool esort(const void*a,const void*b){ // Define a function to sort edges
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return true; // Compare edges based on start vertex
	if((*p).s>(*q).s)return false;
	if((*p).g<(*q).g)return true; // Compare edges based on end vertex
	return false;
}

G g; // Define a global graph variable
void readgraph(){ // Define a function to read the graph
	//適宜変える
	ll n;
	std::cin>>n; // Read the number of vertices
	rep(i,0,n-1){ // Read each edge and store it in the graph structure
		ll x,y,c;
		std::cin>>x>>y>>c;
		g.e.push_back({x,y,c}); // Add the edge to the vector of edges
		g.e.push_back({y,x,c}); // Add the reversed edge to the vector of edges
	}
	g.vcnt=n; // Set the number of vertices
	g.ecnt=2*n-2; // Set the number of edges
	std::sort(g.e.begin(),g.e.end(),esort); // Sort the edges

	int p=0;
	rep(i,0,g.vcnt){ // Populate the id array with the starting index of edges for each vertex
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id.push_back(p); // Add the starting index to the vector of indices
	}
	g.id.push_back(g.ecnt);//番兵 // Add the sentinel value to the vector of indices
}

//木の直径を求める2回dfs
//*
std::vector<int> tyokkeitemp; // Define a temporary vector for DFS
void tyokkeidfs(ll s){ // Define a function to perform DFS and update distances
	for(int i=g.id[s];i<g.id[s+1];i++){
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c; // Update the distance from the root
			tyokkeidfs(g.e[i].g); // Recursively perform DFS
		}
	}
}
int tyokkei(){ // Define a function to find the diameter of the tree
	tyokkeitemp=std::vector<int>(g.vcnt+10,0); // Initialize the temporary vector with zeros
	tyokkeitemp[0]=1; // Start DFS from the root
	tyokkeidfs(0); // Perform DFS
	int M=0,Mi; // Initialize variables to find the maximum distance
	rep(i,0,g.vcnt){ // Find the vertex with the maximum distance from the root
		if(tyokkeitemp[i]>M){
			M=tyokkeitemp[i];
			Mi=i;
		}
	}
	tyokkeitemp=std::vector<int>(g.vcnt+10,0); // Reset the temporary vector
	tyokkeitemp[Mi]=1; // Start DFS from the farthest vertex found
	tyokkeidfs(Mi); // Perform DFS
	rep(i,0,g.vcnt)M=max(M,tyokkeitemp[i]); // Find the maximum distance in the second DFS
	return M-1; // Return the diameter of the tree
}
//*/

int main(){ // Define the main function
	readgraph(); // Read the graph
	std::cout<<tyokkei()<<std::endl; // Print the diameter of the tree
}

