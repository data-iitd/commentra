
public class MatrixMultiplication {

    public static void main(String[] args) {
        int m, n; // Declare variables to store the dimensions of matrix A and vector B
        int i, j; // Declare loop variables
        int A[][] = new int[100][100]; // Declare a 2D array to store matrix A
        int B[] = new int[100]; // Declare an array to store vector B
        int S[] = new int[100]; // Declare an array to store the result of matrix multiplication

        Scanner sc = new Scanner(System.in);
        m = sc.nextInt(); // Read the dimensions of matrix A and vector B
        n = sc.nextInt();

        // Read the elements of matrix A row by row
        for (i = 0; i < m; i++) {
            for (j = 0; j < n - 1; j++) {
                A[i][j] = sc.nextInt();
            }
            A[i][n - 1] = sc.nextInt(); // Read the last element of the row with a newline character
        }

        // Read the elements of vector B
        for (i = 0; i < n; i++) {
            B[i] = sc.nextInt();
        }

        // Perform matrix multiplication of A and B and store the result in array S
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                S[i] = S[i] + A[i][j] * B[j];
            }
        }

        // Print the elements of array S
        for (i = 0; i < m; i++) {
            System.out.println(S[i]);
        }
    }
}

