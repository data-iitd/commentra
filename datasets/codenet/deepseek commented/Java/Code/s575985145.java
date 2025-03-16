
import java.util.Scanner;

public class Main {
	
	public static void main(String [] args) {
		// Initialize Scanner to read input from the user
		Scanner scan = new Scanner(System.in);
		
		// Read the size of the graph
		int size = scan.nextInt();
		
		// Initialize a 2D array to represent the graph
		int[][] graph = new int[size][size];
		
		// Initialize variables to store the row ID, number of columns, and a row array
		int id = 0;
		int cols = 0;
		int[] row = new int[0];
		
		// Loop through each row of the graph
		for(int i = 0; i < size; i++) {
			// Read the row ID and the number of columns
			id = scan.nextInt();
			cols = scan.nextInt();
			
			// Initialize a new row array with the size of the graph
			row = new int[size];
			
			// Loop through each column in the row
			for(int j = 0; j < cols; j++)
				// Set the position in the row array to 1 based on the column index read from input
				row[scan.nextInt() - 1] = 1;
			
			// Assign the row array to the corresponding row in the graph
			graph[id - 1] = row;
		}
		
		// Loop through each row of the graph to print it
		for(int i = 0; i < graph.length; i++) {
			// Loop through each column in the row
			for(int j = 0; j < graph[i].length; j++){
				// Print the value in the graph
				System.out.print(graph[i][j]);
				
				// Print a space if it's not the last column
				if(j < graph[i].length - 1)
					System.out.print(" ");
			}
			// Move to the next line after printing each row
			System.out.println();
		}
	}
}

