
// This is a Java code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
//
// #include <stdio.h>
// #include <stdlib.h>
// #define ll long long
// #define rep(i,l,r)for(ll i=(l);i<(r);i++)
// #define max(p,q)((p)>(q)?(p):(q))

// Define the structure for the edge and graph.
class E{
	public int s,g,c;
	public E(int s,int g,int c){
		this.s = s;
		this.g = g;
		this.c = c;
	}
}
class G{
	public int vcnt,ecnt;
	public E[] e;
	public int[] id;
	public G(int vcnt,int ecnt){
		this.vcnt = vcnt;
		this.ecnt = ecnt;
		e = new E[ecnt+10];
		id = new int[vcnt+10];
	}
}

// Comparison function for qsort to sort edges based on their source vertex.
int esort(E a,E b){
	if(a.s<b.s)return -1;
	if(a.s>b.s)return  1;
	if(a.g<b.g)return -1;
	return 1;
}

// Initialize the graph structure.
G g;

// Read the graph from the standard input.
void readgraph(){
	// Read the number of vertices.
	ll n;
	scanf("%lld",&n);
	// Allocate memory for the vertices and edges.
	g.vcnt = n;
	g.ecnt = 2*n-2;
	// Allocate memory for the edge array and sort it.
	e = new E[g.ecnt+10];
	rep(i,0,n-1){
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		// Add an edge from x to y and y to x with the given cost.
		e[i] = new E(x,y,c);
		e[i+g.ecnt] = new E(y,x,c);
	}
	// Set the number of edges.
	g.ecnt *= 2;
	// Sort the edges using qsort.
	qsort(e,g.ecnt,sizeof(E),esort);
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
	tyokkeitemp = new int[g.vcnt+10];
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

