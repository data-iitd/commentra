import java.util.Scanner;

public class Main {
	
	public static void main(String [] args) {
		// Create a Scanner object to read input from the console
		Scanner scan = new Scanner(System.in);
		
		// Read the size of the graph (number of vertices)
		int size = scan.nextInt();
		
		// Initialize a 2D array to represent the adjacency matrix of the graph
		int[][] graph = new int[size][size];
		
		// Variables to hold the current vertex id and the number of edges (columns)
		int id = 0;
		int cols = 0;
		
		// Temporary array to hold the connections for the current vertex
		int[] row = new int[0];
		
		// Loop through each vertex to read its connections
		for(int i = 0; i < size; i++) {
			// Read the vertex id and the number of connections (edges)
			id = scan.nextInt();
			cols = scan.nextInt();
			
			// Initialize the row array to represent connections for the current vertex
			row = new int[size];
			
			// Read the connections for the current vertex and update the adjacency matrix
			for(int j = 0; j < cols; j++)
				row[scan.nextInt() - 1] = 1; // Mark the connection in the adjacency matrix
			
			// Assign the connections of the current vertex to the graph
			graph[id - 1] = row;
		}
		
		// Print the adjacency matrix of the graph
		for(int i = 0; i < graph.length; i++) {
			for(int j = 0; j < graph[i].length; j++){
				// Print the current value in the adjacency matrix
				System.out.print(graph[i][j]);
				
				// Print a space between values, but not after the last value in the row
				if(j < graph[i].length - 1)
					System.out.print(" ");
			}
			// Move to the next line after printing all columns of the current row
			System.out.println();
		}
	}
}
