/*depth first search
not lie in stack
*/
import java.util.Scanner;

public class Main{
	static final int N=100; // Define the maximum number of nodes
	static final int WHITE=0; // Define WHITE color
	static final int GRAY=1; // Define GRAY color
	static final int BLACK=2; // Define BLACK color

	static int M[][]; // Declare the adjacency matrix and number of nodes
	static int n;
	static int color[]; // Declare color, discovery time, finish time, and time counter
	static int d[];
	static int f[];
	static int tt;

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
		for(int i=0;i<n;i++){
			color[i]=WHITE; // Initialize all nodes to WHITE
		}
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
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt(); // Read the number of nodes
		M=new int[n][n]; // Initialize the adjacency matrix
		color=new int[n];
		d=new int[n];
		f=new int[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				M[i][j]=0; // Initialize the adjacency matrix
		}
		for(int i=0;i<n;i++){
			k=sc.nextInt(); // Read the node and the number of its neighbors
			u=i; // Convert to 0-based index
			for(int j=0;j<k;j++){
				v=sc.nextInt(); // Read the neighbor
				v--; // Convert to 0-based index
				M[u][v]=1; // Set the edge in the adjacency matrix
			}
		}
			
		dfs(); // Perform the depth-first search and print the results

	}
}

