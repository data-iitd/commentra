
public class MatrixMultiplication {

	public static void main(String[] args) {
		int m, n;
		int i, j;
		int A[][] = new int[100][100];
		int B[] = new int[100];
		int S[] = new int[100];

		for (i = 0; i < S.length; i++) {
			S[i] = 0;
		}

		System.out.println("Enter the number of rows and columns of the matrix: ");
		m = sc.nextInt();
		n = sc.nextInt();

		System.out.println("Enter the elements of the matrix: ");
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				A[i][j] = sc.nextInt();
			}
		}

		System.out.println("Enter the elements of the vector: ");
		for (i = 0; i < n; i++) {
			B[i] = sc.nextInt();
		}

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				S[i] = S[i] + A[i][j] * B[j];
			}
		}

		System.out.println("The product of the matrix and the vector is: ");
		for (i = 0; i < m; i++) {
			System.out.println(S[i]);
		}
	}
}

