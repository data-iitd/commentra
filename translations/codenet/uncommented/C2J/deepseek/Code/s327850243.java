public class MatrixVectorMultiplication {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] A = new int[100][100];
        int[] B = new int[100];
        int[] S = new int[100];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                A[i][j] = scanner.nextInt();
            }
            A[i][n - 1] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            B[i] = scanner.nextInt();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                S[i] += A[i][j] * B[j];
            }
        }

        for (int i = 0; i < m; i++) {
            System.out.println(S[i]);
        }
    }
}
