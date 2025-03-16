
import java.io.*;
import java.util.*;

public class s285212630{
    static int N;
    static ArrayList<ArrayList<int[]>> G;
    static int[][] U;
    static int[] R;
    static long[] L;

    static void dfs(int x, int p, int r, long l) {
        U[0][x] = p;
        R[x] = r;
        L[x] = l;
        for (int[] pp : G.get(x)) {
            int t = pp[0];
            if (t == p) continue;
            dfs(t, x, r+1, l+pp[1]);
        }
    }

    static int lca(int a, int b) {
        if (R[a] > R[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        for (int k=0; k<20; k++) {
            if ((R[a] - R[b]) >> k % 1 == 1) {
                b = U[k][b];
            }
        }
        if (a == b) return a;
        for (int k=19; k>=0; k--) {
            if (U[k][a]!= U[k][b]) {
                a = U[k][a];
                b = U[k][b];
            }
        }
        return U[0][a];
    }

    static long dist(int x, int y) {
        int g = lca(x, y);
        return L[x] + L[y] - 2L*L[g];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        N = Integer.parseInt(s[0]);
        G = new ArrayList<>();
        for (int i=0; i<N; i++) {
            G.add(new ArrayList<>());
        }
        for (int i=0; i<N-1; i++) {
            s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0])-1;
            int b = Integer.parseInt(s[1])-1;
            int c = Integer.parseInt(s[2]);
            G.get(a).add(new int[]{b, c});
            G.get(b).add(new int[]{a, c});
        }
        U = new int[20][N];
        R = new int[N];
        L = new long[N];
        dfs(0, -1, 0, 0);
        for (int i=0; i<19; i++) {
            for (int j=0; j<N; j++) {
                if (U[i][j] == -1) {
                    U[i+1][j] = -1;
                } else {
                    U[i+1][j] = U[i][U[i][j]];
                }
            }
        }
        String[] qs = br.readLine().split(" ");
        int Q = Integer.parseInt(qs[0]);
        int K = Integer.parseInt(qs[1])-1;
        for (int i=0; i<Q; i++) {
            s = br.readLine().split(" ");
            int x = Integer.parseInt(s[0])-1;
            int y = Integer.parseInt(s[1])-1;
            System.out.println(dist(x, K) + dist(K, y));
        }
    }
}

