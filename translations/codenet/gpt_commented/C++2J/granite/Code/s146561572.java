
import java.util.*;
import java.io.*;

public class s146561572{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        // Read the number of test cases
        // t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br, out);
        }
        out.close();
    }
    
    static void solve(BufferedReader br, PrintWriter out) throws IOException {
        long ans = 0; // Initialize the answer variable
        int n = Integer.parseInt(br.readLine()); // Read the number of nodes

        // Calculate the contribution of each node to the answer
        for (int i = 1; i <= n; i++) {
            ans += i * 1l * (n - i + 1); // Contribution of node i
        }

        // Adjust the answer based on the edges between nodes
        for (int i = 1; i < n; i++) {
            String[] edge = br.readLine().split(" "); // Read the edge connecting nodes u and v
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);
            int a = Math.max(u, v); // Determine the maximum node
            int b = Math.min(u, v); // Determine the minimum node
            ans -= b * 1l * (n - a + 1); // Subtract the contribution of the edge
        }

        // Output the final answer
        out.println(ans);
    }
}

