import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    static int n, m, l, r, vi;
    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    // Function to read an integer from input
    static int read() throws IOException {
        int k = 0, f = 1;
        char ch = (char) System.in.read();
        // Skip non-digit characters and check for negative sign
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = (char) System.in.read();
        }
        // Construct the integer from the digits read
        while (ch >= '0' && ch <= '9') {
            k = k * 10 + ch - '0';
            ch = (char) System.in.read();
        }
        return k * f; // Return the final integer with sign
    }

    // Function to find the representative of a set and update the value
    static int get(int x) {
        if (x == fa[x]) return x; // If x is its own parent, return it
        int f = get(fa[x]); // Recursively find the root
        v[x] += v[fa[x]]; // Update the value based on the parent
        return fa[x] = f; // Path compression
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        n = read(); // Read number of nodes
        m = read(); // Read number of edges
        // Initialize the parent array for union-find
        for (int i = 1; i <= n; i++) fa[i] = i;
        // Process each edge
        for (int i = 1; i <= m; i++) {
            l = read(); // Read left node
            r = read(); // Read right node
            vi = read(); // Read value to be assigned
            int li = get(l), ri = get(r); // Find representatives of both nodes
            // If they belong to different sets, union them
            if (li != ri) {
                v[ri] = vi - v[r] + v[l]; // Update the value for the new root
                fa[ri] = li; // Union the sets
            } else {
                // If they are in the same set, check for consistency
                if (v[r] - v[l] != vi) {
                    out.println("No"); // Inconsistent values
                    out.flush();
                    return; // Exit the program
                }
            }
        }
        out.println("Yes"); // All edges processed successfully
        out.flush(); // Ensure all output is printed
    }
}
// <END-OF-CODE>
