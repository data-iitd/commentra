import java.util.Scanner;

public class MatrixIdenticalRows {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of rows and columns from the user
        int N = scanner.nextInt();
        int D = scanner.nextInt();

        // Allocate memory for the 2D matrix
        int[][] matrix = new int[N][D];

        // Read the elements of the matrix from the user
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Calculate the number of identical rows
        int k = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int m = 0; // Initialize the variable m to 0
                for (int n = 0; n < D; n++) {
                    // Calculate the difference between the corresponding elements of two rows and square it
                    m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
                }
                // Calculate the square root of the sum of squared differences
                double l = Math.sqrt(m);
                // If the square root is an integer, increment the counter k
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }

        // Print the result
        System.out.println(k);
    }
}
