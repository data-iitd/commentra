import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of nodes N
        int N = Integer.parseInt(input.readLine().trim());
        
        // Initialize adjacency list to store the graph
        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        
        // Read N-1 edges and populate the adjacency list
        for (int i = 0; i < N - 1; i++) {
            String[] edge = input.readLine().trim().split(" ");
            int a = Integer.parseInt(edge[0]);
            int b = Integer.parseInt(edge[1]);
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
        int[] childNum = new int[N + 1];
        
        // Perform BFS to find parent and child relationships
        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u : adj.get(v)) {
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    childNum[v]++;
                    que.add(u);
                }
            }
        }
        
        // Find leaf nodes (nodes with no children)
        Deque<Integer> seq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (childNum[i] == 0) {
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
            childNum[par[par[c]]]--;
            if (childNum[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }
        
        // If no winning strategy is found for the first player, print 'Second'
        System.out.println("Second");
    }
}
// <END-OF-CODE>
