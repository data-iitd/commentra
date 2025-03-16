import java.util.Scanner;

public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        // Declare variables for the number of rows (m) and columns (n)
        int m, n;
        // Loop counters
        int i, j;
        // Declare a 2D array A for storing the matrix and a 1D array B for the vector
        int[][] A = new int[100][100];
        int[] B = new int[100];
        // Declare an array S to store the results of the matrix-vector multiplication, initialized to 0
        int[] S = new int[100];

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the dimensions of the matrix (m rows and n columns)
        m = scanner.nextInt();
        n = scanner.nextInt();

        // Input the matrix A
        for (i = 0; i < m; i++) {
            // Read each row of the matrix
            for (j = 0; j < n; j++) {
                A[i][j] = scanner.nextInt(); // Read elements of the row
            }
        }

        // Input the vector B
        for (i = 0; i < n; i++) {
            B[i] = scanner.nextInt(); // Read each element of the vector
        }

        // Perform matrix-vector multiplication
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                S[i] += A[i][j] * B[j]; // Calculate the dot product for each row
            }
        }

        // Output the result of the multiplication
        for (i = 0; i < m; i++) {
            System.out.println(S[i]); // Print each element of the result array S
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
