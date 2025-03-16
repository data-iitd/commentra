public class Prim {
    static final int INF = 100000;
    static final int MAX = 101;
    static final int NIL = -6;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;

    static int[][] G = new int[MAX][MAX];
    static int n;

    public static void prim() {
        int[] d = new int[MAX];
        int[] pi = new int[MAX];
        int[] color = new int[MAX];
        int min, u, v, sum = 0;

        for (int i = 0; i < n; i++) {
            d[i] = INF;
            pi[i] = NIL;
            color[i] = WHITE;
        }

        d[0] = 0;

        while (true) {
            min = INF;
            u = NIL;
            for (int i = 0; i < n; i++) {
                if (color[i] != BLACK && d[i] < min) {
                    min = d[i];
                    u = i;
                }
            }
            if (u == NIL) {
                break;
            }
            color[u] = BLACK;
            for (v = 0; v < n; v++) {
                if (color[v] != BLACK && G[u][v] != INF) {
                    if (d[v] > G[u][v]) {
                        d[v] = G[u][v];
                        pi[v] = u;
                        color[v] = GRAY;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (pi[i] != NIL) sum += G[i][pi[i]];
        }
        System.out.println(sum);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int e = scanner.nextInt();
                if (e == -1) {
                    G[i][j] = INF;
                } else {
                    G[i][j] = e;
                }
            }
        }

        prim();
    }
}
