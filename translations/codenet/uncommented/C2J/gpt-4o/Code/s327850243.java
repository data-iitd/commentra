import java.util.Scanner;

public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        
        int[][] A = new int[100][100];
        int[] B = new int[100];
        int[] S = new int[100];
        
        // Initialize S array to 0
        for (int i = 0; i < 100; i++) {
            S[i] = 0;
        }

        // Read matrix A
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = scanner.nextInt();
            }
        }

        // Read vector B
        for (int i = 0; i < n; i++) {
            B[i] = scanner.nextInt();
        }

        // Perform matrix-vector multiplication
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                S[i] += A[i][j] * B[j];
            }
        }

        // Print the result
        for (int i = 0; i < m; i++) {
            System.out.println(S[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
