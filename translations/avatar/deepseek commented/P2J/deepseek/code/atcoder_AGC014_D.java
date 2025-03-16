import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // Initialize adjacency list to store the graph
        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        // Read N-1 edges and populate the adjacency list
        for (int i = 0; i < N - 1; i++) {
            String[] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        // Initialize deque for BFS and seen array to track visited nodes
        Deque<Integer> que = new ArrayDeque<>();
        que.add(1);
        int[] seen = new int[N + 1];
        seen[1] = 1;

        // Array to store parent nodes
        int[] par = new int[N + 1];

        // Array to count the number of children for each node
        int[] child_num = new int[N + 1];

        // Perform BFS to find parent and child relationships
        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u : adj.get(v)) {
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    child_num[v]++;
                    que.add(u);
                }
            }
        }

        // Find leaf nodes (nodes with no children)
        Deque<Integer> seq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
            }
        }

        // Process leaf nodes to determine the winning strategy
        while (!seq.isEmpty()) {
            int c = seq.pollLast();
            seen[c] = 0;
            if (seen[par[c]] == 0) {
                System.out.println("First");
                return;
            }
            seen[par[c]] = 0;
            child_num[par[par[c]]]--;
            if (child_num[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }

        // If no winning strategy is found for the first player, print 'Second'
        System.out.println("Second");
    }
}
