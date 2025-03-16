import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N, D, i, j, k = 0, n = 0;
		double l;
		int[][] matrix;
		N = in.nextInt();
		D = in.nextInt();
		matrix = new int[N][D];
		for (i = 0; i < N; i++) {
			for (j = 0; j < D; j++) {
				matrix[i][j] = in.nextInt();
			}
		}
		for (i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				int m = 0;
				for (n = 0; n < D; n++) {
					m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m;
				}
				l = Math.sqrt(m);
				if (Math.ceil(l) == Math.floor(l)) k++;
			}
		}
		System.out.println(k);
	}
}
