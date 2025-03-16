import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Reading Input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        int k = 0;

        // Allocate memory for the matrix
        int[][] matrix = new int[N][D];

        // Step 2: Inputting Points
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // Step 3: Calculating Distances
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int m = 0;
                for (int n = 0; n < D; n++) {
                    m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
                }
                double l = Math.sqrt(m);
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }

        // Step 4: Outputting the Result
        System.out.println(k);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
