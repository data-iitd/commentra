import java.io.*;
import java.util.*;

public class Main {
    // g is a static array of ArrayLists that will store the graph's adjacency list representation.
    static ArrayList<Integer>[] g;

    // maxMatching method calculates the maximum matching in a tree structure.
    static int maxMatching(int v, int p) {
        int a = 0; // Number of matched pairs
        int o = 0; // Number of unmatched nodes
        for (int w : g[v]) {
            if (w == p) continue; // Skip the parent node
            int r = maxMatching(w, v); // Recursively calculate matching for child nodes
            a += r / 2; // Add half of the matches from the child
            o += r % 2; // Count the unmatched nodes
        }
        return 2 * a + Math.min(1, o) + 1; // Return the total number of matches
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        MyScanner sc = new MyScanner(); // Create a scanner object to read input
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt(); // Read the number of nodes
        g = new ArrayList[n]; // Initialize the graph's adjacency list
        Arrays.setAll(g, x -> new ArrayList<Integer>());
        for (int i = 0; i < n - 1; ++i) { // Read the edges and construct the graph
            int a = sc.nextInt() - 1; // Read node a and convert to 0-based index
            int b = sc.nextInt() - 1; // Read node b and convert to 0-based index
            g[a].add(b); // Add edge from a to b
            g[b].add(a); // Add edge from b to a
        }
        int m = maxMatching(0, -1) / 2; // Calculate the maximum matching
        out.println(2 * m == n ? "Second" : "First"); // Determine the winner and print the result
        out.close(); // Close the output stream
    }

    public static PrintWriter out;

    // MyScanner class reads input from the standard input stream.
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
