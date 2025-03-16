import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    // NextLine reads a line of input
    private static String nextLine() throws IOException {
        return reader.readLine();
    }

    // NextInt reads an integer from input
    private static int nextInt() throws IOException {
        return Integer.parseInt(nextLine());
    }

    // Write prints a line to the output
    private static void write(Object s) throws IOException {
        writer.write(s.toString());
        writer.newLine();
    }

    // Output flushes the writer to ensure all buffered data is written
    private static void output() throws IOException {
        writer.flush();
    }

    // Bipartite checks if a graph is bipartite
    private static boolean bipartite(String[] S) {
        int N = S.length;
        int[] D = new int[N]; // Distance array
        D[0] = 1; // Start from the first vertex
        boolean ret = true; // Return value
        Queue<Integer> Q = new LinkedList<>();
        Q.add(0); // Start BFS from the first vertex

        while (!Q.isEmpty() && ret) {
            int q = Q.poll();
            for (int j = 0; j < N; j++) {
                if (S[q].charAt(j) == '0') {
                    continue;
                }
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

    // WarshallFloyd computes the shortest paths between all pairs of vertices
    private static int warshallFloyd(String[] S) {
        int N = S.length;
        int[][] G = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    G[i][j] = 0; // Distance to self is 0
                } else if (S[i].charAt(j) == '0') {
                    G[i][j] = N; // Set distance to a large number
                } else {
                    G[i][j] = 1; // Direct edge weight
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G[i][k] + G[k][j] < G[i][j]) {
                        G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (ans < G[i][j]) {
                    ans = G[i][j]; // Find the maximum distance
                }
            }
        }
        return ans + 1; // Return the result
    }

    // Main function to execute the program
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = nextLine();
        }
        if (!bipartite(S)) {
            write(-1); // If not bipartite, write -1
        } else {
            write(warshallFloyd(S)); // Otherwise, compute and write the result
        }
        output(); // Flush the writer
    }
}

// <END-OF-CODE>
