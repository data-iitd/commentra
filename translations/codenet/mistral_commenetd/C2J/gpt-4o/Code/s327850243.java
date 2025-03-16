import java.util.Scanner;

public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        // Declare variables
        int m, n;
        int i, j;
        int[][] A = new int[100][100];
        int[] B = new int[100];
        int[] S = new int[100];

        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Read the dimensions of the matrices from user
        m = scanner.nextInt();
        n = scanner.nextInt();

        // Comments for the for loop: Read the elements of matrix A row-wise
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = scanner.nextInt();
            }
        }

        // Comments for the for loop: Read the elements of vector B
        for (i = 0; i < n; i++) {
            B[i] = scanner.nextInt();
        }

        // Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                S[i] += A[i][j] * B[j];
            }
        }

        // Comments for the for loop: Print the elements of vector S
        for (i = 0; i < m; i++) {
            System.out.println(S[i]);
        }

        // The program ends with a return statement with value 0
        scanner.close();
    }
}

// <END-OF-CODE>
