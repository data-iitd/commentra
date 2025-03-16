
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, D, i, j, k = 0, n = 0;
		double l;
		int[][] matrix;

		// Read the number of rows and columns from the user
		System.out.print("Enter the number of rows and columns: ");
		N = sc.nextInt();
		D = sc.nextInt();

		// Allocate memory for the 2D matrix
		matrix = new int[N][D];

		// Read the elements of the matrix from the user
		System.out.print("Enter the elements of the matrix:\n");
		for (i = 0; i < N; i++) {
			System.out.print("Row " + (i + 1) + ": ");
			for (j = 0; j < D; j++) {
				matrix[i][j] = sc.nextInt();
			}
		}

		// Calculate the number of identical rows
		k = 0;
		for (i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				int m = 0; // Initialize the variable m to 0
				for (n = 0; n < D; n++) {
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

		sc.close();
	}
}

