#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

//辺の情報を個別に持つタイプ
class E{
	int s,g,c;
	public E(int s,int g,int c){
		this.s=s;
		this.g=g;
		this.c=c;
	}
}

class G{
	int vcnt,ecnt;
	E[] e;//適宜変える
	int[] id;//適宜変える
	public G(int vcnt,int ecnt){
		this.vcnt=vcnt;
		this.ecnt=ecnt;
		e=new E[2*ecnt];
		id=new int[vcnt];
	}
}

int esort(E a,E b){ // Define a function to sort edges
	if(a.s<b.s)return -1; // Compare edges based on start vertex
	if(a.s>b.s)return  1;
	if(a.g<b.g)return -1; // Compare edges based on end vertex
	return 1;
}

G g; // Define a global graph variable
void readgraph(){ // Define a function to read the graph
	//適宜変える
	int n;
	scanf("%d",&n); // Read the number of vertices
	rep(i,0,n-1){ // Read each edge and store it in the graph structure
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		g.e[2*i]=new E(x,y,c);
		g.e[2*i+1]=new E(y,x,c);
	}
	g.vcnt=n; // Set the number of vertices
	g.ecnt=2*n-2; // Set the number of edges
	Arrays.sort(g.e,esort); // Sort the edges

	int p=0;
	rep(i,0,g.vcnt){ // Populate the id array with the starting index of edges for each vertex
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵 // Set the sentinel value for the id array
}

//木の直径を求める2回dfs
//*
int[]tyokkeitemp; // Define a temporary array for DFS
void tyokkeidfs(int s){ // Define a function to perform DFS and update distances
	for(int i=g.id[s];i<g.id[s+1];i++){
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
			tyokkeidfs(g.e[i].g);
		}
	}
}
int tyokkei(){ // Define a function to find the diameter of the tree
	tyokkeitemp=new int[g.vcnt+10]; // Allocate memory for the temporary array
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
	return M-1; // Return the diameter of the tree
}
//*/

int main(){ // Define the main function
	readgraph(); // Read the graph
	printf("%d\n",tyokkei()); // Print the diameter of the tree
}

