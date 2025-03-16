
import java.util.Scanner;

public class s327850243{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] A = new int[m][n];
        int[] B = new int[n];
        int[] S = new int[m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                A[i][j] = sc.nextInt();
            }
            A[i][n - 1] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            B[i] = sc.nextInt();
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
