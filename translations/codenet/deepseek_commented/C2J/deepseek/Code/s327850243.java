public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int m = scanner.nextInt(); // Read the dimensions of matrix A and vector B
        int n = scanner.nextInt(); // Read the dimensions of matrix A and vector B
        int[][] A = new int[100][100]; // Declare a 2D array to store matrix A
        int[] B = new int[100]; // Declare an array to store vector B
        int[] S = new int[100]; // Declare an array to store the result of matrix multiplication

        // Read the elements of matrix A row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                A[i][j] = scanner.nextInt();
            }
            A[i][n - 1] = scanner.nextInt(); // Read the last element of the row
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
    }
}
