import java.util.Scanner;

public class VectorDistance {
    public static void main(String[] args) {
        // Declare variables for number of vectors (N), dimensions (D), and loop counters
        int N, D, k = 0;
        double l; // Variable to store the distance between two vectors
        Scanner scanner = new Scanner(System.in);

        // Read the number of vectors (N) and their dimensions (D) from user input
        N = scanner.nextInt();
        D = scanner.nextInt();

        // Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
        int[][] matrix = new int[N][D];

        // Read the vectors from user input and store them in the matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Calculate the pairwise distances between all vectors
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int m = 0; // Variable to accumulate the squared differences
                // Calculate the squared distance between vector i and vector j
                for (int n = 0; n < D; n++) {
                    m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
                }
                // Calculate the Euclidean distance
                l = Math.sqrt(m);
                // Check if the distance is an integer (i.e., if its ceiling equals its floor)
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }

        // Output the count of pairs of vectors with integer distances
        System.out.println(k);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
