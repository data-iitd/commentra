/*depth first search
not lie in stack
*/
import java.util.*;
public class Main{
	static final int N=100; // Define the maximum number of nodes
	static final int WHITE=0; // Define WHITE color
	static final int GRAY=1; // Define GRAY color
	static final int BLACK=2; // Define BLACK color
	static int M[][]; // Declare the adjacency matrix
	static int color[]; // Declare color
	static int d[],f[],tt,n; // Declare discovery time, finish time, and time counter
	
	// Depth-first search visit function
	static void dfs_visit(int u){
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
	static void dfs(){
		int u;
		color=new int[N]; // Initialize all nodes to WHITE
		d=new int[N]; // Initialize all nodes to -1
		f=new int[N]; // Initialize all nodes to -1
		tt=0; // Reset the time counter
		
		for(u=0;u<n;u++){
			if(color[u]==WHITE) // If u is WHITE, start a DFS from u
				dfs_visit(u);
		}
		
		for(int i=0;i<n;i++)
			System.out.println(i+1+" "+d[i]+" "+f[i]); // Print the discovery and finish times for each node
	}
	
	public static void main(String[] args){
		int k,u,v;
		Scanner cin=new Scanner(System.in);
		n=cin.nextInt(); // Read the number of nodes
		M=new int[N][N]; // Initialize the adjacency matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				M[i][j]=0; // Initialize the adjacency matrix
		}
		for(int i=0;i<n;i++){
			u=cin.nextInt(); // Read the node and the number of its neighbors
			k=cin.nextInt();
			u--; // Convert to 0-based index
			for(int j=0;j<k;j++){
				v=cin.nextInt(); // Read the neighbor
				v--; // Convert to 0-based index
				M[u][v]=1; // Set the edge in the adjacency matrix
			}
		}
		
		dfs(); // Perform the depth-first search and print the results
	}
}

