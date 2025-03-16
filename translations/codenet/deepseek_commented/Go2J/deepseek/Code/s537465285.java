import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    static String nextLine() throws IOException {
        String line;
        while ((line = reader.readLine()) != null) {
            return line;
        }
        return null;
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextLine());
    }

    static void write(Object s) {
        writer.println(s);
    }

    static void output() {
        writer.flush();
    }

    static boolean bipartite(String[] S) {
        int N = S.length;
        int[] D = new int[N];
        D[0] = 1;
        Queue<Integer> Q = new LinkedList<>();
        Q.add(0);
        boolean ret = true;
        while (!Q.isEmpty() && ret) {
            int q = Q.poll();
            for (int j = 0; j < N; j++) {
                if (S[q].charAt(j) == '0') continue;
                if (D[j] == 0) {
                    D[j] = D[q] + 1;
                    Q.add(j);
                } else if (D[j] % 2 == D[q] % 2) {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }

    static int warshallFloyd(String[] S) {
        int N = S.length;
        int[][] G = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (S[i].charAt(j) == '0') {
                    G[i][j] = N;
                } else {
                    G[i][j] = 1;
                }
            }
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G[i][k] + G[k][j] < G[i][j]) {
                        G[i][j] = G[i][k] + G[k][j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (ans < G[i][j]) ans = G[i][j];
            }
        }
        return ans + 1;
    }

    public static void main(String[] args) throws IOException {
        int N = nextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = nextLine();
        }
        if (!bipartite(S)) {
            write(-1);
        } else {
            write(warshallFloyd(S));
        }
        output();
    }
}
