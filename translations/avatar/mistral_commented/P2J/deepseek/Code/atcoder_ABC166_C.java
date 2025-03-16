import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input containing the number of nodes 'n' and edges 'm'
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a list 'p' of numbers from 1 to 'n'
        List<Integer> p = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            p.add(i);
        }
        
        // Read the second line of input containing the heights of the nodes
        List<Integer> h = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            h.add(scanner.nextInt());
        }
        
        // Create a dictionary 'hp' to store node number as key and height as value
        Map<Integer, Integer> hp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hp.put(p.get(i), h.get(i));
        }
        
        // Initialize an empty dictionary 'path' to store the graph
        Map<Integer, List<Integer>> path = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            path.put(i, new ArrayList<>());
        }
        
        // Read 'm' lines of input containing edges and add them to the 'path' dictionary
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            path.get(a).add(b);
            path.get(b).add(a);
        }
        
        // Initialize a counter 'c' to store the number of valid paths
        int c = 0;
        
        // Iterate through each node in the graph and check if it forms a valid path
        for (int i : path.keySet()) {
            // Initialize a flag 'f' to check if the current node is a valid starting point
            boolean f = false;
            // Iterate through each neighbor of the current node and check if it is a valid ending point
            for (int j : path.get(i)) {
                // If the height of the current node is less than or equal to the height of its neighbor,
                // then it is not a valid path and we set the flag 'f' to true and break the loop
                if (hp.get(i) <= hp.get(j)) {
                    f = true;
                    break;
                }
            }
            // If the flag 'f' is still false after checking all neighbors, then this node forms a valid path
            // and we increment the counter 'c'
            if (!f) {
                c++;
            }
        }
        
        // Print the final result, i.e., the number of valid paths
        System.out.println(c);
    }
}

