public class DepthFirstSearch {
    static final int N = 200;
    static final int SHIRO = 0;
    static final int HAI = 1;
    static final int KURO = 2;

    static void aaaaa();
    static void bbbbb(int);

    static int n, A[][] = new int[N][N];
    static int color[] = new int[N];
    static int d[] = new int[N];
    static int f[] = new int[N];
    static int TT;

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

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

        aaaaa();
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
