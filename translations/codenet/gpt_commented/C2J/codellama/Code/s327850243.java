
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

        // Read the dimensions of the matrix (m rows and n columns)
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();

        // Input the matrix A
        for(i = 0; i < m; i++) {
            // Read each row of the matrix
            for(j = 0; j < n - 1; j++) {
                A[i][j] = sc.nextInt(); // Read elements of the row
            }
            // Read the last element of the row
            A[i][n - 1] = sc.nextInt();
        }

        // Input the vector B
        for(i = 0; i < n; i++) {
            B[i] = sc.nextInt(); // Read each element of the vector
        }

        // Perform matrix-vector multiplication
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                S[i] = S[i] + A[i][j] * B[j]; // Calculate the dot product for each row
            }
        }

        // Output the result of the multiplication
        for(i = 0; i < m; i++) {
            System.out.println(S[i]); // Print each element of the result array S
        }
    }
}

