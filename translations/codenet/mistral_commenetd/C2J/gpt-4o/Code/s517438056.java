import java.util.Scanner;

public class MatrixIdenticalRows {
    public static void main(String[] args) {
        // Declare variables
        int N, D, k = 0;
        double l;

        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Read the number of rows and columns from the user
        System.out.print("Enter the number of rows and columns: ");
        N = scanner.nextInt();
        D = scanner.nextInt();

        // Allocate memory for the 2D matrix
        int[][] matrix = new int[N][D];

        // Read the elements of the matrix from the user
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < N; i++) {
            System.out.print("Row " + (i + 1) + ": ");
            for (int j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Calculate the number of identical rows
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int m = 0; // Initialize the variable m to 0
                for (int n = 0; n < D; n++) {
                    // Calculate the difference between the corresponding elements of two rows and square it
                    m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
                }
                // Calculate the square root of the sum of squared differences
                l = Math.sqrt(m);
                // If the square root is an integer, increment the counter k
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }

        // Print the result
        System.out.println(k);

        // Close the scanner
        scanner.close();
    }
}
