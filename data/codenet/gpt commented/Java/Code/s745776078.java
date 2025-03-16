import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object for input and a PrintWriter for output
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        // Read the dimensions of the matrix: n (rows) and m (columns)
        int n = in.nextInt(), m = in.nextInt();
        
        // Initialize a 2D array A of size n x m and a 1D array b of size m
        int A[][] = new int[n][m], b[] = new int[m];
        
        // Read the elements of the matrix A from input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = in.nextInt(); // Fill matrix A with input values
            }
        }
        
        // Read the elements of the vector b from input
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt(); // Fill vector b with input values
        }
        
        // For each row in matrix A, calculate the dot product with vector b
        for (int i = 0; i < n; i++) {
            int c = 0; // Initialize the dot product result for the current row
            for (int j = 0; j < m; j++) {
                c += A[i][j] * b[j]; // Calculate the dot product
            }
            out.println(c); // Output the result of the dot product
        }
        
        // Flush the output to ensure all data is written
        out.flush();
    }
}
