import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of nodes N and the number of edges M
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        // Initialize adjacency lists for each node
        List<Set<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<>());
        }
        
        // Initialize degrees for each node
        int[] degs = new int[N];
        
        // Initialize parity for each node
        int[] parity = new int[N];
        
        // Initialize flag to mark visited nodes
        boolean[] flag = new boolean[N];
        
        // Read each edge and update adjacency lists and degree lists
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edges.get(a - 1).add(b - 1);
            edges.get(b - 1).add(a - 1);
            degs[a - 1]++;
            degs[b - 1]++;
        }
        
        // If the number of edges M is odd, print -1 and exit
        if (M % 2!= 0) {
            System.out.println(-1);
            return;
        }
        
        // Initialize a heap Q with nodes based on their degrees
        PriorityQueue<Pair> Q = new PriorityQueue<>((a, b) -> a.first - b.first);
        for (int i = 0; i < N; i++) {
            Q.add(new Pair(degs[i], i));
        }
        
        // Process nodes from the heap
        while (!Q.isEmpty()) {
            Pair p = Q.poll();
            int u = p.second;
            
            // If the node has already been processed, skip to the next iteration
            if (flag[u]) {
                continue;
            }
            
            // Mark the node as processed
            flag[u] = true;
            
            // For each neighbor of the node, update the adjacency list and degree list
            for (int v : edges.get(u)) {
                edges.get(v).remove(u);
                
                // Print the edge in the required format, alternating the direction based on the parity
                if (parity[u]!= 0) {
                    System.out.println(u + 1 + " " + v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println(v + 1 + " " + u + 1);
                    parity[v] = 1 - parity[v];
                }
                
                // Update the degree and push the updated node back into the heap
                degs[v]--;
                Q.add(new Pair(degs[v], v));
        }
    }
    
    // A simple pair class
    static class Pair {
        int first, second;
        Pair(int a, int b) {
            first = a;
            second = b;
        }
    }
}

