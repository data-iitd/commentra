import java.util.*; // Importing necessary libraries for handling input and output operations
import java.io.*;   // Importing necessary libraries for handling input and output operations

public class Main {

	public static void main(String[] args) { // Main method is the entry point of the program
		Scanner in = new Scanner(System.in); // Creating a Scanner object to read input from the standard input stream
		PrintWriter out = new PrintWriter(System.out); // Creating a PrintWriter object to write output to the standard output stream
		int n = in.nextInt(), m = in.nextInt(), A[][] = new int[n][m], b[] = new int[m]; // Reading the dimensions and initializing the arrays
		
		for(int i = 0; i < n; i++) { // Loop to read the elements of the matrix A row by row
			for(int j = 0; j < m; j++) A[i][j] = in.nextInt();
		}
		
		for(int i = 0; i < m; i++) b[i] = in.nextInt(); // Loop to read the elements of the array b
		
		for(int i = 0; i < n; i++) { // Loop to calculate and print the dot product of each row of A with the array b
			int c = 0;
			for(int j = 0; j < m; j++) {
				c += A[i][j] * b[j];
			}
			out.println(c);
		}
		
		out.flush(); // Flushing the output to ensure all buffered output is written to the output stream
	}

}
