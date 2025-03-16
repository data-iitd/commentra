import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    static String NextLine() throws IOException {
        String line;
        StringBuilder buffer = new StringBuilder();
        boolean isPrefix = true;
        while (isPrefix) {
            line = reader.readLine();
            if (line == null) {
                throw new IOException();
            }
            buffer.append(line);
            isPrefix = line.endsWith("\n");
        }
        return buffer.toString();
    }

    static int NextInt() throws IOException {
        return Integer.parseInt(NextLine());
    }

    static void Write(Object s) {
        writer.println(s);
    }

    static void Output() {
        writer.flush();
    }

    static boolean Bipartite(String[] S) {
        int N = S.length;
        int[] D = new int[N];
        D[0] = 1;
        int[] Q = new int[N];
        boolean ret = true;
        int pos = 1;
        for (int i = 0; i < N; i++) {
            if (!ret) break;
            int q = Q[i];
            for (int j = 0; j < N; j++) {
                char s = S[q].charAt(j);
                if (s == '0') {
                    continue;
                }
                if (D[j] == 0) {
                    D[j] = D[q] + 1;
                    Q[pos] = j;
                    pos++;
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

    static int WarshallFloyd(String[] S) {
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
        int N = NextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = NextLine();
        }
        if (!Bipartite(S)) {
            Write(-1);
        } else {
            Write(WarshallFloyd(S));
        }
        Output();
    }
}
