
// Header Files and Preprocessor Directives
import java.io.*;
import java.util.*;

// Main Class
public class Main{
	// Function to read input
	public static int nextint(){
		try{
			return Integer.parseInt(br.readLine());
		}catch(Exception e){
			return -1;
		}
	}

	// Global Variables
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static int n;
	static int a[][];
	static int e1[];
	static int e2[];
	static int d[];
	static boolean b[];

	// Function Definitions
	public static int p(int a, int b){
		if(a<b){
			return a+b*n;
		}else{
			return b+a*n;
		}
	}

	public static int f(int from){
		if(b[from]) return -1; // If node is already visited, return -1 indicating a cycle
		if(d[from]) return d[from]; // If distance is already calculated, return it
		b[from]=true; // Mark the node as visited
		int to;
		to = e1[from];
		int max=0;
		if(to!=0){
			int now=f(to); // Recursively find the longest path from 'to'
			if(now<0) return now; // If there's a cycle, return -1
			if(now>max) max=now; // Update max if a longer path is found
		}
		to = e2[from];
		if(to!=0){
			int now=f(to); // Recursively find the longest path from 'to'
			if(now<0) return now; // If there's a cycle, return -1
			if(now>max) max=now; // Update max if a longer path is found
		}
		b[from]=false; // Unmark the node as visited (backtracking)
		return d[from]=max+1; // Store and return the longest path length
	}

	// Main Function
	public static void main(String args[]){
		n=nextint(); // Read the size of the problem
		a=new int[n][n-1];
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1; j++){
				a[i][j]=nextint()-1; // Read and adjust indices to be 0-based
			}
		}
		e1=new int[n*n];
		e2=new int[n*n];
		d=new int[n*n];
		b=new boolean[n*n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n-2; j++){
				int from = p(i, a[i][j]); // Create a unique node index 'from'
				int to = p(i, a[i][j+1]); // Create a unique node index 'to'
				if(e1[from]==0){
					e1[from]=to; // Assign 'to' to e1 of 'from'
				}else if(e2[from]==0){
					e2[from]=to; // Assign 'to' to e2 of 'from'
				}else{
					System.out.println("-1"); // If both e1 and e2 are already assigned, print -1 and exit
					return;
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int from = p(i, a[i][0]); // Create a unique starting node index 'from'
			int now=f(from); // Find the longest path from 'from'
			if(now<0){
				ans=-1; // If there's a cycle, set ans to -1
				break;
			}
			if(now>ans) ans=now; // Update ans if a longer path is found
		}
		System.out.println(ans); // Print the result
	}
}

