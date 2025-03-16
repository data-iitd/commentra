import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Input the number of nodes (n) and the number of edges (m)
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        
        // Step 2: Create a list of positions (p) from 1 to n
        List<Integer> p = new ArrayList<>();
        for (int x = 1; x <= n; x++) {
            p.add(x);
        }
        
        // Step 3: Input the heights (h) of the nodes
        String[] heightsInput = scanner.nextLine().split(" ");
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = Integer.parseInt(heightsInput[i]);
        }
        
        // Step 4: Create a map (hp) mapping positions to heights
        Map<Integer, Integer> hp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hp.put(p.get(i), h[i]);
        }
        
        // Step 5: Initialize a map (path) to store the adjacency list of the graph
        Map<Integer, List<Integer>> path = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            path.put(i, new ArrayList<>());
        }
        
        // Step 6: Input the edges of the graph and populate the adjacency list
        for (int i = 0; i < m; i++) {
            String[] edgeInput = scanner.nextLine().split(" ");
            int a = Integer.parseInt(edgeInput[0]);
            int b = Integer.parseInt(edgeInput[1]);
            path.get(a).add(b);
            path.get(b).add(a);
        }
        
        // Step 7: Count the number of nodes that are the highest in their neighborhoods
        int c = 0;
        for (Map.Entry<Integer, List<Integer>> entry : path.entrySet()) {
            int i = entry.getKey();
            List<Integer> neighbors = entry.getValue();
            boolean isHighest = true;
            for (int j : neighbors) {
                if (hp.get(i) <= hp.get(j)) {
                    isHighest = false;
                    break;
                }
            }
            if (isHighest) {
                c++;
            }
        }
        
        // Step 8: Output the count of such nodes
        System.out.println(c);
        
        scanner.close();
    }
}
// <END-OF-CODE>
