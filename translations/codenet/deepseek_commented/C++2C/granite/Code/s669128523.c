
/*depth first search
not lie in stack
*/
#include <stdio.h>
#define N 100 // Define the maximum number of nodes
#define WHITE 0 // Define WHITE color
#define GRAY 1 // Define GRAY color
#define BLACK 2 // Define BLACK color

int M[N][N],n; // Declare the adjacency matrix and number of nodes
int color[N],d[N],f[N],tt; // Declare color, discovery time, finish time, and time counter

// Depth-first search visit function
void dfs_visit(int u){
	int v;
	color[u]=GRAY; // Set the color of node u to GRAY
	d[u]=++tt; // Record the discovery time of u
	for(v=0;v<n;v++){
		if(M[u][v]==0)
			continue; // Skip if there is no edge from u to v
		if(color[v]==WHITE){ // If v is WHITE, recursively visit v
			dfs_visit(v);
		}
	}
	color[u]=BLACK; // Set the color of node u to BLACK
	f[u]=++tt; // Record the finish time of u
}

// Depth-first search function
void dfs(){
	int u;
	for(int i=0;i<n;i++){
		color[i]=WHITE; // Initialize all nodes to WHITE
	}
	tt=0; // Reset the time counter
	
	for(u=0;u<n;u++){
		if(color[u]==WHITE) // If u is WHITE, start a DFS from u
			dfs_visit(u);
	}
	
	for(int i=0;i<n;i++)
		printf("%d %d %d\n",i+1,d[i],f[i]); // Print the discovery and finish times for each node
}

int main(){
	
	int k,u,v;
	scanf("%d",&n); // Read the number of nodes
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			M[i][j]=0; // Initialize the adjacency matrix
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&u,&k); // Read the node and the number of its neighbors
		u--; // Convert to 0-based index
		for(int j=0;j<k;j++){
			scanf("%d",&v); // Read the neighbor
			v--; // Convert to 0-based index
			M[u][v]=1; // Set the edge in the adjacency matrix
		}
	}
		
	dfs(); // Perform the depth-first search and print the results

	return 0;
}
