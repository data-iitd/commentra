import java.util.*; // Importing the utility class Scanner from java.util package
import java.io.*;   // Importing the PrintWriter class from java.io package

public class Main {

	public static void main(String[] args) { // Main method where the execution starts
		Scanner in=new Scanner(System.in); // Creating a new Scanner object to read input from the standard input
		PrintWriter out=new PrintWriter(System.out); // Creating a new PrintWriter object to write output to the standard output
		int n=in.nextInt(),m=in.nextInt(); // Reading the number of rows and columns from the input

		// Creating a 2D integer array A of size n x m to store the input matrix
		int A[][]=new int[n][m];

		// Reading the elements of matrix A into the array
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)A[i][j]=in.nextInt();
		}

		// Reading the elements of vector b into an array
		int b[]=new int[m];
		for(int i=0;i<m;i++)b[i]=in.nextInt();

		// Performing matrix-vector multiplication and printing the result for each row
		for(int i=0;i<n;i++) {
			int c=0; // Initializing a variable c to store the dot product of each row with vector b
			for(int j=0;j<m;j++) {
				c+=A[i][j]*b[j]; // Multiplying each element of the current row with the corresponding element of vector b and adding to the variable c
			}
			out.println(c); // Printing the result for the current row
		}

		// Flushing the PrintWriter buffer to write all the output to the standard output
		out.flush();
	}

}
