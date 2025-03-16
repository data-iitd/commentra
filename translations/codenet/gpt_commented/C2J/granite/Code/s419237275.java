
import java.util.Scanner;

public class s419237275{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] A = new int[n][n];
        int[] color = new int[n];
        int[] d = new int[n];
        int[] f = new int[n];
        int TT = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1;
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1;
                A[u][v] = 1;
            }
        }

        aaaaa(n, A, color, d, f, TT);

        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }

    public static void aaaaa(int n, int[][] A, int[] color, int[] d, int[] f, int TT) {
        for (int i = 0; i < n; i++) {
            color[i] = 0;
        }

        TT = 0;

        for (int u = 0; u < n; u++) {
            if (color[u] == 0) {
                bbbbb(n, A, color, d, f, TT, u);
            }
        }
    }

    public static void bbbbb(int n, int[][] A, int[] color, int[] d, int[] f, int TT, int k) {
        color[k] = 1;
        TT++;
        d[k] = TT;

        for (int v = 0; v < n; v++) {
            if (A[k][v] == 0) {
                continue;
            }
            if (color[v] == 0) {
                bbbbb(n, A, color, d, f, TT, v);
            }
        }

        color[k] = 2;
        TT++;
        f[k] = TT;
    }
}

