public class VectorDistance {
    public static void main(String[] args) {
        // Declare variables for number of vectors (N), dimensions (D), and loop counters
        int N, D, i, j, k = 0, n = 0;
        double l; // Variable to store the distance between two vectors
        int[][] matrix; // 2D array to hold the vectors

        // Read the number of vectors (N) and their dimensions (D) from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        D = scanner.nextInt();

        // Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
        matrix = new int[N][D];

        // Read the vectors from user input and store them in the matrix
        for (i = 0; i < N; i++) {
            for (j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Calculate the pairwise distances between all vectors
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                int m = 0; // Variable to accumulate the squared differences
                // Calculate the squared distance between vector i and vector j
                for (n = 0; n < D; n++) {
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
    }
}
