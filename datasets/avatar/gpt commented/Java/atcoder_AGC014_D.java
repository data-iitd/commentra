import java.io.*; 
import java.util.*; 

public class Main {
    // Adjacency list to represent the graph
    static ArrayList<Integer>[] g; 

    // Function to calculate the maximum matching in the graph
    static int maxMatching(int v, int p) {
        int a = 0; // Count of pairs in matching
        int o = 0; // Count of unmatched vertices
        
        // Iterate through all adjacent vertices of v
        for (int w : g[v]) {
            // Skip the parent vertex to avoid cycles
            if (w == p) continue; 
            
            // Recursively find the matching for the adjacent vertex
            int r = maxMatching(w, v); 
            a += r / 2; // Update count of pairs
            o += r % 2; // Update count of unmatched vertices
        }
        
        // Return the total matching count
        return 2 * a + Math.min(1, o) + 1; 
    } 

    @SuppressWarnings("unchecked") 
    public static void main(String[] args) {
        // Initialize scanner for input
        MyScanner sc = new MyScanner(); 
        // Initialize output writer
        out = new PrintWriter(new BufferedOutputStream(System.out)); 
        
        // Read the number of vertices
        int n = sc.nextInt(); 
        // Initialize the adjacency list for the graph
        g = new ArrayList[n]; 
        Arrays.setAll(g, x -> new ArrayList<Integer>()); 
        
        // Read edges and populate the adjacency list
        for (int i = 0; i < n - 1; ++i) {
            int a = sc.nextInt() - 1; // Read vertex a
            int b = sc.nextInt() - 1; // Read vertex b
            g[a].add(b); // Add edge to the graph
            g[b].add(a); // Add edge to the graph (undirected)
        }
        
        // Calculate maximum matching starting from vertex 0
        int m = maxMatching(0, -1) / 2; 
        
        // Determine the winner based on the matching result
        out.println(2 * m == n ? "Second" : "First"); 
        
        // Close the output writer
        out.close(); 
    } 

    // Output writer for printing results
    public static PrintWriter out; 

    // Custom scanner class for efficient input reading
    public static class MyScanner {
        BufferedReader br; // Buffered reader for input
        StringTokenizer st; // Tokenizer for parsing input
        
        // Constructor to initialize the buffered reader
        public MyScanner() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        
        // Method to read the next token
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        
        // Method to read the next integer
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next long
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next double
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line
        String nextLine() { 
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
}
