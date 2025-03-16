import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    private static String nextLine() throws IOException {
        return reader.readLine();
    }

    private static int nextInt() throws IOException {
        return Integer.parseInt(nextLine());
    }

    private static void write(Object s) throws IOException {
        writer.write(s.toString());
        writer.newLine();
    }

    private static void output() throws IOException {
        writer.flush();
    }

    private static boolean bipartite(String[] S) {
        int N = S.length;
        int[] D = new int[N];
        D[0] = 1;
        int[] Q = new int[N];
        boolean ret = true;
        int pos = 1;

        for (int i = 0; i < N; i++) {
            if (!ret) break;
            int q = Q[i];
            for (int j = 0; j < S[q].length(); j++) {
                char s = S[q].charAt(j);
                if (s == '0') {
                    continue;
                }
                if (D[j] == 0) {
                    D[j] = D[q] + 1;
                    Q[pos++] = j;
                    continue;
                }
                if (D[j] % 2 == D[q] % 2) {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }

    private static int warshallFloyd(String[] S) {
        int N = S.length;
        int[][] G = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                G[i][j] = (S[i].charAt(j) == '0') ? N : 1;
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

// <END-OF-CODE>
