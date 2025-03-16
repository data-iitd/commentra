import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    // Initialize reader and writer
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter writer = new PrintWriter(System.out);

    // Function to read a single line from standard input
    private static String nextLine() throws IOException {
        return reader.readLine();
    }

    // Function to read an integer from standard input
    private static int nextInt() throws IOException {
        return Integer.parseInt(nextLine());
    }

    // Function to check if a given graph is bipartite
    private static boolean isBipartite(String[] S) {
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

                if (D[j] % 2 != D[q] % 2) {
                    ret = false;
                    break;
                }
            }
        }

        return ret;
    }

    // Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
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
                if (ans < G[i][j]) {
                    ans = G[i][j];
                }
            }
        }

        return ans + 1;
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Read number of vertices
        int N = nextInt();

        // Initialize graph
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = nextLine();
        }

        // Check if graph is bipartite
        if (!isBipartite(S)) {
            // Write -1 if graph is not bipartite
            writer.println(-1);
        } else {
            // Write shortest distance between all pairs of vertices
            writer.println(warshallFloyd(S));
        }

        // Flush writer buffer
        writer.flush();
    }
}
// <END-OF-CODE>
