
import java.io.* ;  // Importing required Java packages for input and output
import java.util.* ;

public class Main {
    // Declaring static variables
    static ArrayList<Integer>[] g ;
    static int maxMatching; // To store the maximum number of edges that can be matched in a bipartite graph

    // Function to find the maximum number of edges that can be matched in a bipartite graph
    static int maxMatching(int v, int p) {
        int a = 0; // Number of edges matched from the neighboring vertices of 'v'
        int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

        // Iterating through all the neighbors of 'v'
        for (int w : g[v]) {
            if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

            // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
            int r = maxMatching(w, v);
            a += r / 2;
            o += r % 2;
        }

        // Returning the result based on the parity of 'o'
        return 2 * a + Math.min(1, o);
    }

    @SuppressWarnings("unchecked") // Suppressing the warning for unchecked generic array creation
    public static void main(String[] args) {
        // Creating an instance of MyScanner class for reading input
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out)); // Creating an instance of PrintWriter for output

        // Reading the number of vertices in the graph
        int n = sc.nextInt();

        // Initializing the graph as an ArrayList of ArrayLists
        g = new ArrayList[n];
        Arrays.setAll(g, x -> new ArrayList<>());

        // Reading the edges and adding them to the graph
        for (int i = 0; i < n - 1; ++i) {
            int a = sc.nextInt() - 1; // Reading the first vertex of the edge
            int b = sc.nextInt() - 1; // Reading the second vertex of the edge
            g[a].add(b); // Adding the edge from 'a' to 'b'
            g[b].add(a); // Adding the edge from 'b' to 'a'
        }

        // Finding the maximum number of edges that can be matched in the graph
        maxMatching = maxMatching(0, -1) / 2;

        // Printing the result based on whether all vertices have even degree or not
        out.println(2 * maxMatching == n ? "Second" : "First");

        // Closing the output stream
        out.close();
    }

    public static PrintWriter out;
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        // Constructor for MyScanner class
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        // Function to read the next token from the input stream
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

        // Overloaded functions for reading different data types
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

These comments should provide a clear understanding of the code for anyone who reads it.