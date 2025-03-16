
import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // Input the number of nodes, starting and ending nodes
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ta = sc.nextInt();
        int ao = sc.nextInt();
        ta--;
        ao--;

        // Initialize an adjacency list
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read edges and add them to the graph
        for (int i = 0; i < n-1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            g.get(a-1).add(b-1);
            g.get(b-1).add(a-1);
        }

        // Initialize distance arrays for both nodes
        int[] ta_dist = new int[n];
        int[] ao_dist = new int[n];

        // Initialize distances for starting and ending nodes
        ta_dist[ta] = 0;
        ao_dist[ao] = 0;

        // Depth First Search from starting node to calculate distances from starting node
        void ta_dfs(int node) {
            for (int v : g.get(node)) {
                if (ta_dist[v]!= 0) continue;
                ta_dist[v] = ta_dist[node] + 1;
                ta_dfs(v);
            }
        }

        // Depth First Search from ending node to calculate distances from ending node
        void ao_dfs(int node) {
            for (int v : g.get(node)) {
                if (ao_dist[v]!= 0) continue;
                ao_dist[v] = ao_dist[node] + 1;
                ao_dfs(v);
            }
        }

        // Perform Depth First Search from starting and ending nodes
        ao_dfs(ao);
        ta_dfs(ta);

        // Calculate the answer
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] == 0 || ao_dist[i] == 0 || ta_dist[i] > ao_dist[i]) continue;
            res = Math.max(res, ao_dist[i]);
        }

        // Print the answer
        System.out.println(res-1);
    }
}

