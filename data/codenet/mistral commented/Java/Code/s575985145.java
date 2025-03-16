import java.util.Scanner; // Importing Scanner class for user input

public class Main {
	
	public static void main(String [] args) { // Main method to start the program
		Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read user input
		int size = scan.nextInt(); // Reading the size of the graph from user input
		int[][] graph = new int[size][size]; // Creating a 2D integer array of size x size to represent the graph

		int id = 0; // Initializing id variable to 0
		int cols = 0; // Initializing cols variable to 0
		int[] row = new int[0]; // Initializing row array of size 0

		for(int i = 0; i < size; i++) { // Loop to read the graph data from user input
			id = scan.nextInt(); // Reading the id of the node
			cols = scan.nextInt(); // Reading the number of columns connected to the node
			row = new int[size]; // Creating a new row array of size size for the current node

			for(int j = 0; j < cols; j++) { // Loop to read the columns connected to the node
				row[scan.nextInt() - 1] = 1; // Setting the value of the corresponding index in the row array to 1
			}
			graph[id - 1] = row; // Assigning the row array to the corresponding index in the graph array
		}

		// Printing the graph matrix
		for(int i = 0; i < graph.length; i++) {
			for(int j = 0; j < graph[i].length; j++){
				System.out.print(graph[i][j]); // Printing the value of the current cell
				if(j < graph[i].length - 1) // Checking if the current cell is not the last one in the row
					System.out.print(" "); // Printing a space if it's not the last cell
			}
			System.out.println(); // Printing a newline after each row
		}
	}
}
