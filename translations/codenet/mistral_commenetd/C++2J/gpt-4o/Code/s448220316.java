import java.io.*;

public class Main {
    // Initialize variables
    static int n, m, l, r, vi;
    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    // Inline function to get the root of a tree
    static int get(int x) {
        if (fa[x] == x) return x; // Base case: the root of the tree is itself
        // Recursively find the root of the tree
        int f = get(fa[x]);
        // Update the depth of the nodes on the path from 'x' to the root
        v[x] += v[fa[x]];
        // Update the father of 'x'
        fa[x] = f;
        return f;
    }

    // Main function
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        // Read the number of vertices 'n' and edges 'm'
        String[] firstLine = br.readLine().split(" ");
        n = Integer.parseInt(firstLine[0]);
        m = Integer.parseInt(firstLine[1]);

        // Initialize the trees for each vertex
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }

        // Process each edge
        for (int i = 1; i <= m; i++) {
            // Read the left and right endpoints and the value 'vi' of the edge
            String[] edgeLine = br.readLine().split(" ");
            l = Integer.parseInt(edgeLine[0]);
            r = Integer.parseInt(edgeLine[1]);
            vi = Integer.parseInt(edgeLine[2]);

            // Find the roots of the trees of the left and right endpoints
            int li = get(l), ri = get(r);
            // If the roots are different, update the depth of the right tree and its father
            if (li != ri) {
                v[ri] += vi - v[r] + v[l]; // Update the depth of the right tree
                fa[ri] = li; // Set the father of the right tree to the father of the left tree
            } else {
                // If the roots are the same, check if the value of the edge is correct
                if (v[r] - v[l] != vi) {
                    out.println("No"); // Output 'No' if the value is incorrect
                    out.flush();
                    return; // Terminate the program
                }
            }
        }
        // Output 'Yes' if all edges have the correct value
        out.println("Yes");
        out.flush();
    }
}
// <END-OF-CODE>
