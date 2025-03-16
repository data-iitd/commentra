
// This is a C++ code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
//
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define rep(i,l,r)for(ll i=(l);i<(r);i++)
// #define max(p,q)((p)>(q)?(p):(q))

// Define the structure for the edge and graph.
struct edge{ll s,g,c;}; // An edge has source, destination, and cost.
struct graph{
	int vcnt,ecnt; // Number of vertices and edges in the graph.
	edge  e[200010]; // Array to store edges.
	int id[100010]; // Array to store the index of each vertex in the sorted edge list.
};

// Comparison function for qsort to sort edges based on their source vertex.
int esort(const void*a,const void*b){
	edge*p=(edge*)a,*q=(edge*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

// Initialize the graph structure.
graph g;

// Read the graph from the standard input.
void readgraph(){
	// Read the number of vertices.
	ll n;
	scanf("%lld",&n);
	// Allocate memory for the vertices and edges.
	g.vcnt = n;
	g.ecnt = 2*n-2;
	// Allocate memory for the edge array and sort it.
	e = (edge*)calloc(g.ecnt+10,sizeof(edge));
	rep(i,0,n-1){
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		// Add an edge from x to y and y to x with the given cost.
		e[i].s = x;
		e[i].g = y;
		e[i].c = c;
		e[i+g.ecnt].s = y;
		e[i+g.ecnt].g = x;
		e[i+g.ecnt].c = c;
	}
	// Set the number of edges.
	g.ecnt *= 2;
	// Sort the edges using qsort.
	qsort(e,g.ecnt,sizeof(edge),esort);
	// Initialize the id array.
	int p = 0;
	rep(i,0,g.vcnt){
		// Find the index of the current vertex in the sorted edge list.
		while(p<g.ecnt&&e[p].s<i)p++;
		g.id[i] = p;
	}
	// Set the last index as a sentinel.
	g.id[g.vcnt] = g.ecnt;
}

// Function to find the diameter of the tree using DFS algorithm.
// *tyokkeitemp is an array to store the depth of each vertex from the root.
int*tyokkeitemp;
void tyokkeidfs(ll s){
	// Iterate through the edges connected to the current vertex.
	for(int i=g.id[s];i<g.id[s+1];i++){
		// If the destination vertex has not been visited yet, recursively call tyokkeidfs.
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
			tyokkeidfs(g.e[i].g);
		}
	}
}
int tyokkei(){
	// Allocate memory for tyokkeitemp array.
	tyokkeitemp = (int*)calloc(g.vcnt+10,sizeof(int));
	// Initialize the root vertex depth to 1.
	tyokkeitemp[0] = 1;
	// Perform DFS from the root vertex.
	tyokkeidfs(0);
	// Find the maximum depth.
	int M = 0, Mi;
	rep(i,0,g.vcnt){
		// If the current vertex depth is greater than the maximum depth, update it.
		if(tyokkeitemp[i]>M){
			M = tyokkeitemp[i];
			Mi = i;
		}
	}
	// Free the memory allocated for tyokkeitemp.
	free(tyokkeitemp);
	// Return the diameter which is the maximum depth minus 1.
	return M-1;
}
// Main function to read the graph and print the diameter.
int main(){
	// Read the graph.
	readgraph();
	// Call the tyokkei function to find the diameter.
	printf("%d\n",tyokkei());
	// Free the memory allocated for the edge array.
	free(e);
	return 0;
}

