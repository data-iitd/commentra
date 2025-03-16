import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Read the number of nodes N
        int N = Integer.parseInt(br.readLine());

        // Initialize adjacency list to store the graph
        ArrayList<Integer>[] adj = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        // Read N-1 edges and populate the adjacency list
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }

        // Initialize deque for BFS and seen array to track visited nodes
        Deque<Integer> que = new ArrayDeque<>();
        que.add(1);
        boolean[] seen = new boolean[N + 1];
        seen[1] = true;

        // Array to store parent nodes
        int[] par = new int[N + 1];

        // Array to count the number of children for each node
        int[] child_num = new int[N + 1];

        // Perform BFS to find parent and child relationships
        while (!que.isEmpty()) {
            int v = que.poll();
            for (int u : adj[v]) {
                if (!seen[u]) {
                    seen[u] = true;
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
            int c = seq.poll();
            seen[c] = false;
            if (!seen[par[c]]) {
                System.out.println("First");
                return;
            }
            seen[par[c]] = false;
            child_num[par[par[c]]]--;
            if (child_num[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }

        // If no winning strategy is found for the first player, print 'Second'
        System.out.println("Second");
    }
}

