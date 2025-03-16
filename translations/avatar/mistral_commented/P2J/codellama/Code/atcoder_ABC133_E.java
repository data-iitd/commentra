#######
// Import necessary modules and set recursion limit
#######
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // Initialize an empty graph using HashMap
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<Integer, ArrayList<Integer>>();

        // Read input: number of nodes N and color limit K
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Read edges between nodes and add them to the graph
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (graph.containsKey(a)) {
                graph.get(a).add(b);
            } else {
                ArrayList<Integer> list = new ArrayList<Integer>();
                list.add(b);
                graph.put(a, list);
            }
            if (graph.containsKey(b)) {
                graph.get(b).add(a);
            } else {
                ArrayList<Integer> list = new ArrayList<Integer>();
                list.add(a);
                graph.put(b, list);
            }
        }

        // Define a recursive function dfs to calculate the answer
        int mod = 1000000007;
        public int dfs(int fro, int to, int f) {
            // Initialize case number and color number
            int caseNum = 1;
            int colorNum = K - 1;

            // Iterate through the neighbors of the current node
            for (int u : graph.get(fro)) {
                // Skip the target node
                if (u == to) {
                    continue;
                }

                // Recursively call dfs on the neighbor and update case number
                int pat = dfs(u, fro, colorNum);
                if (pat == 0) {
                    caseNum = 0;
                    break;
                }
                caseNum = (caseNum * pat) % mod;
                colorNum--;
            }

            // Return the final case number
            return caseNum;
        }

        // Call the dfs function with initial values and print the result
        int ans = dfs(0, -1, K);
        System.out.println(ans);
    }
}
