import java.util.*; 
import java.util.Map.*; 

public class Main { 
    // Array to store colors assigned to each point
    private static int[] colors; 

    public static void main(String[] args) throws Exception { 
        // Create a scanner to read input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of points (nodes)
        int n = sc.nextInt(); 
        
        // Calculate the number of edges (m = n - 1 for a tree)
        int m = n - 1; 
        
        // Initialize colors array with -1 (indicating uncolored)
        colors = new int[n]; 
        Arrays.fill(colors, -1); 
        
        // Create an array of Point objects
        Point[] points = new Point[n]; 
        
        // Initialize each Point object with its index
        for (int i = 0; i < n; i++) { 
            points[i] = new Point(i); 
        } 
        
        // Read edges and establish friendships between points
        while (m-- > 0) { 
            int me = sc.nextInt() - 1; // Read first point (0-indexed)
            int you = sc.nextInt() - 1; // Read second point (0-indexed)
            int length = sc.nextInt(); // Read the length of the friendship
            
            // Establish friendship in both directions
            points[me].becomeFriend(points[you], length); 
            points[you].becomeFriend(points[me], length); 
        } 
        
        // Start DFS from the first point (index 0)
        dfs(points[0], 0); 
        
        // Output the colors assigned to each point
        for (int c : colors) { 
            System.out.println(c); 
        } 
    } 

    // Depth-First Search (DFS) to assign colors based on friendship lengths
    public static void dfs(Point p, int length) { 
        // Check if the point has already been colored
        boolean alreadyKnown = colors[p.name] != -1; 
        if (alreadyKnown) return; // Exit if already colored
        
        // Assign color based on the length (even or odd)
        if (length % 2 == 0) { 
            colors[p.name] = 0; // Even length -> color 0
        } else { 
            colors[p.name] = 1; // Odd length -> color 1
        } 
        
        // Recursively visit all friends of the current point
        for (Entry<Point, Integer> entry : p.friends.entrySet()) { 
            Point friend = entry.getKey(); // Get the friend point
            int length2 = entry.getValue(); // Get the length of friendship
            dfs(friend, length + length2); // Recursive DFS call
        } 
    } 

    // Class representing a point in the graph
    public static class Point { 
        int name; // Unique identifier for the point
        Map<Point, Integer> friends; // Map to store friends and their friendship lengths
        
        // Constructor to initialize the point with its name
        Point(int name) { 
            this.name = name; 
            this.friends = new HashMap<Point, Integer>(); // Initialize friends map
        } 
        
        // Method to establish friendship with another point
        void becomeFriend(Point p, int length) { 
            this.friends.put(p, length); // Add friend with the specified length
        } 
    } 
}
