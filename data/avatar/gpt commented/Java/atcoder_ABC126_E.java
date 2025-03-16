import java.util.*; 

public class Main {
    // Scanner object to read input from the console
    Scanner sc = new Scanner(System.in); 
    // Constant for modulo operation
    final int MOD = 1000000007; 

    // Method to execute the main logic
    void doIt() { 
        // Read the number of elements (nodes)
        int n = sc.nextInt(); 
        // Initialize Union-Find data structure with n elements
        UnionFindTree utf = new UnionFindTree(n); 
        // Read the number of connections (edges)
        int m = sc.nextInt(); 
        
        // Process each connection
        for (int i = 0; i < m; i++) { 
            // Read the two nodes to unite and the weight (not used in this implementation)
            int x = sc.nextInt() - 1; 
            int y = sc.nextInt() - 1; 
            int z = sc.nextInt(); 
            // Unite the two nodes
            utf.unite(x, y); 
        } 
        
        // Count the number of unique connected components
        int cnt = 0; 
        for (int i = 0; i < n; i++) { 
            // Check if the current node is a root of a component
            if (utf.par[i] == i) { 
                cnt++; 
            } 
        } 
        
        // Output the count of unique connected components
        System.out.println(cnt); 
    } 

    // Inner class implementing Union-Find (Disjoint Set Union)
    class UnionFindTree { 
        int n; // Number of elements
        int[] par; // Parent array
        int[] rank; // Rank array for union by rank

        // Constructor to initialize the Union-Find structure
        UnionFindTree(int n) { 
            this.n = n; 
            par = new int[n]; 
            rank = new int[n]; 
            // Initialize each element to be its own parent and rank to 0
            for (int i = 0; i < n; i++) { 
                par[i] = i; 
                rank[i] = 0; 
            } 
        } 

        // Find the root of the set containing x with path compression
        int find(int x) { 
            if (par[x] == x) { 
                return x; 
            } else { 
                return par[x] = find(par[x]); 
            } 
        } 

        // Unite the sets containing x and y
        void unite(int x, int y) { 
            x = find(x); 
            y = find(y); 
            // If they are already in the same set, do nothing
            if (x == y) return; 
            // Union by rank
            if (rank[x] < rank[y]) 
                par[x] = y; 
            else { 
                par[y] = x; 
                if (rank[x] == rank[y]) 
                    rank[x]++; 
            } 
        } 

        // Check if x and y are in the same set
        boolean same(int x, int y) { 
            return find(x) == find(y); 
        } 
    } 

    // Main method to start the program
    public static void main(String[] args) { 
        new Main().doIt(); 
    } 
}
