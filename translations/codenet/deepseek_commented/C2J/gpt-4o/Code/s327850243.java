import java.util.Scanner;

public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int m, n; // Declare variables to store the dimensions of matrix A and vector B
        m = scanner.nextInt();
        n = scanner.nextInt();
        
        int[][] A = new int[100][100]; // Declare a 2D array to store matrix A
        int[] B = new int[100]; // Declare an array to store vector B
        int[] S = new int[100]; // Declare an array to store the result of matrix multiplication

        // Read the elements of matrix A row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = scanner.nextInt();
            }
        }

        // Read the elements of vector B
        for (int i = 0; i < n; i++) {
            B[i] = scanner.nextInt();
        }

        // Perform matrix multiplication of A and B and store the result in array S
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                S[i] += A[i][j] * B[j];
            }
        }

        // Print the elements of array S
        for (int i = 0; i < m; i++) {
            System.out.println(S[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
