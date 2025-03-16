import java.util.*;
import java.io.*;
public class Main {
    // Define a structure to represent an edge in the graph
    static class edge{ int to, pre, c; }
    static edge e[] = new edge[1000010]; int u[] = new int[1000010]; int l = 0;
    static void ins(int a, int b, int c) { e[++l] = new edge(), e[l].to = b, e[l].pre = u[a], e[l].c = c, u[a] = l; }
    // Define some variables and arrays for storing information about the graph
    static int n, m;
    static boolean vis[] = new boolean[1000010];
    static long cnt[] = new long[3];
    static int d[] = new int[1000010];
    static int T;
    // Define a function to perform a depth-first search of the graph
    static void dfs(int x, int l) {
        vis[x] = true; cnt[l]++; d[x] = l;
        for (int i = u[x]; i; i = e[i].pre) {
            T++;
            if (!vis[e[i].to]) dfs(e[i].to, (l + e[i].c) % 3);
            else if ((l + e[i].c) % 3!= d[e[i].to]) return;
        }
    }
    // Define the main function to read the input and compute the answer
    public static void main(String[] args) throws Exception {
        // Read the input n and m, where n is the number of nodes and m is the number of edges
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ss = br.readLine().split(" ");
        n = Integer.parseInt(ss[0]); m = Integer.parseInt(ss[1]);
        // Initialize some variables and arrays
        long ans = 0;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            T = 0;
            for (int j = 0; j < 3; j++) cnt[j] = 0;
            // Perform a depth-first search for the current unvisited node
            dfs(i, 0); long s = cnt[0] + cnt[1] + cnt[2];
            // Compute the answer based on the information obtained during the depth-first search
            if (cnt[0] && cnt[1] && cnt[2]) 
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
            else 
                ans += T / 2;
        }
        // Output the answer and terminate the program
        System.out.println(ans);
    }
}

