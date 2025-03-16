import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize p and h
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i + 1;
        }
        
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        
        // Create hp map
        Map<Integer, Integer> hp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hp.put(p[i], h[i]);
        }
        
        // Create path adjacency list
        Map<Integer, List<Integer>> path = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            path.put(i, new ArrayList<>());
        }
        
        // Read edges
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            path.get(a).add(b);
            path.get(b).add(a);
        }
        
        // Count the nodes
        int c = 0;
        for (Map.Entry<Integer, List<Integer>> entry : path.entrySet()) {
            int i = entry.getKey();
            List<Integer> v = entry.getValue();
            boolean f = false;
            for (int j : v) {
                if (hp.get(i) <= hp.get(j)) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                c++;
            }
        }
        
        // Print the result
        System.out.println(c);
        
        scanner.close();
    }
}
// <END-OF-CODE>
