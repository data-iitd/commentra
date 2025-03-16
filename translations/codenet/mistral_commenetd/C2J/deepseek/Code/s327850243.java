import java.util.Scanner;

public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables
        int m, n;
        int i, j;
        int[][] A = new int[100][100];
        int[] B = new int[100];
        int[] S = new int[100];

        // Read the dimensions of the matrices from user
        m = scanner.nextInt();
        n = scanner.nextInt();

        // Comments for the for loop: Read the elements of matrix A row-wise
        for (i = 0; i < m; i++) {
            for (j = 0; j < n - 1; j++) {
                A[i][j] = scanner.nextInt();
            }
            // Read the last element of the row
            A[i][n - 1] = scanner.nextInt();
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
