#include<stdio.h>
#include<math.h>
#include<stdlib.h>

public class Main {
	public static void main(String[] args) {
		int N, D, i, j, k = 0, n = 0;
		double l;
		int[][] matrix;
		scanf("%d%d", &N, &D);
		matrix = new int[N][D];
		for ( i = 0; i < N; i++){
			matrix[i] = new int[D];
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < D; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		for (i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				int m = 0;
				for (n = 0; n < D; n++) {
					m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m;
				}
				l = sqrt(m);
				if (ceil(l) == floor(l)) k++;
			}
		}
		printf("%d\n", k);
		free(matrix);
		return 0;
	}
}

