import java.util.*;
import java.io.*;

// Define the structure for edges
class E{
	int s,g,c;
	E(int s,int g,int c){
		this.s=s;
		this.g=g;
		this.c=c;
	}
}

// Define the structure for the graph
class G{
	int vcnt,ecnt;
	E[] e;
	int[] id;
	G(int vcnt,int ecnt){
		this.vcnt=vcnt;
		this.ecnt=ecnt;
		e=new E[ecnt];
		id=new int[vcnt+1];
	}
}

// Define a function to sort edges
class SortEdges implements Comparator<E>{
	public int compare(E a,E b){
		if(a.s<b.s)return -1;
		if(a.s>b.s)return 1;
		if(a.g<b.g)return -1;
		if(a.g>b.g)return 1;
		return 0;
	}
}

// Define a function to read the graph
void readgraph(G g){
	// Read the number of vertices
	int n;
	Scanner sc=new Scanner(System.in);
	n=sc.nextInt();
	// Read each edge and store it in the graph structure
	for(int i=0;i<2*n-2;i++){
		int x,y,c;
		x=sc.nextInt();
		y=sc.nextInt();
		c=sc.nextInt();
		g.e[i]=new E(x,y,c);
	}
	g.vcnt=n; // Set the number of vertices
	g.ecnt=2*n-2; // Set the number of edges
	Arrays.sort(g.e,new SortEdges()); // Sort the edges

	int p=0;
	for(int i=0;i<g.vcnt;i++){ // Populate the id array with the starting index of edges for each vertex
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵 // Set the sentinel value for the id array
}

//木の直径を求める2回dfs
class TreeDiameter{
	// Define a temporary array for DFS
	int[] tyokkeitemp;
	// Define a function to perform DFS and update distances
	void tyokkeidfs(G g,int s){
		for(int i=g.id[s];i<g.id[s+1];i++){
			if(tyokkeitemp[g.e[i].g]==0){
				tyokkeitemp[g.e[i].g]=tyokkeitemp[s]+g.e[i].c;
				tyokkeidfs(g.e[i].g);
			}
		}
	}
	// Define a function to find the diameter of the tree
	int tyokkei(G g){
		tyokkeitemp=new int[g.vcnt+10]; // Allocate memory for the temporary array
		tyokkeitemp[0]=1; // Start DFS from the root
		tyokkeidfs(g,0); // Perform DFS
		int M=0,Mi; // Initialize variables to find the maximum distance
		for(int i=0;i<g.vcnt;i++){ // Find the vertex with the maximum distance from the root
			if(tyokkeitemp[i]>M){
				M=tyokkeitemp[i];
				Mi=i;
			}
		}
		for(int i=0;i<g.vcnt)tyokkeitemp[i]=0; // Reset the temporary array
		tyokkeitemp[Mi]=1; // Start DFS from the farthest vertex found
		tyokkeidfs(g,Mi); // Perform DFS
		for(int i=0;i<g.vcnt)M=Math.max(M,tyokkeitemp[i]); // Find the maximum distance in the second DFS
		return M-1; // Return the diameter of the tree
	}
}

// Define the main function
public class Main{
	public static void main(String[] args){
		G g=new G(0,0); // Define a global graph variable
		readgraph(g); // Read the graph
		TreeDiameter td=new TreeDiameter(); // Define a tree diameter class
		System.out.println(td.tyokkei(g)); // Print the diameter of the tree
	}
}

