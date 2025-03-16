
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(reader.readLine());
        List<String> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            S.add(reader.readLine());
        }

        if (!isBipartite(S)) {
            writer.write("-1");
        } else {
            writer.write(String.valueOf(warshallFloyd(S)));
        }

        writer.flush();
    }

    private static boolean isBipartite(List<String> S) {
        int N = S.size();
        int[] D = new int[N];
        D[0] = 1;
        int[] Q = new int[N];
        boolean ret = true;
        int pos = 1;

        for (int i = 0; i < N; i++) {
            if (!ret) {
                break;
            }
            int q = Q[i];
            for (int j = 0; j < N; j++) {
                if (S.get(q).charAt(j) == '0') {
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

    private static int warshallFloyd(List<String> S) {
        int N = S.size();
        int[][] G = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                if (S.get(i).charAt(j) == '0') {
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
                if (ans < G[i][j]) {
                    ans = G[i][j];
                }
            }
        }
        return ans + 1;
    }
}

