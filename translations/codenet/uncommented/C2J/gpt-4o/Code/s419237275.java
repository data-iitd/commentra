import java.util.Scanner;

public class GraphTraversal {
    static final int N = 200;
    static final int SHIRO = 0;
    static final int HAI = 1;
    static final int KURO = 2;

    static int[][] A = new int[N][N];
    static int[] color = new int[N];
    static int[] d = new int[N];
    static int[] f = new int[N];
    static int TT;
    static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int u, k, v;

        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            u--; // Adjusting for 0-based index
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt();
                v--; // Adjusting for 0-based index
                A[u][v] = 1;
            }
        }

        aaaaa();

        scanner.close();
    }

    static void aaaaa() {
        for (int i = 0; i < n; i++) {
            color[i] = SHIRO;
        }

        TT = 0;

        for (int u = 0; u < n; u++) {
            if (color[u] == SHIRO) {
                bbbbb(u);
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
        }
    }

    static void bbbbb(int k) {
        color[k] = HAI;
        TT++;
        d[k] = TT;
        for (int v = 0; v < n; v++) {
            if (A[k][v] == 0) continue;
            if (color[v] == SHIRO) {
                bbbbb(v);
            }
        }
        color[k] = KURO;
        f[k] = ++TT;
    }
}

// <END-OF-CODE>
