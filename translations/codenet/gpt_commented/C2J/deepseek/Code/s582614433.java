public class Main {
    public static void main(String[] args) {
        // Read the number of edges
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        // Array to hold edge data
        Edge[] data = new Edge[100];
        
        // Read edge data from input
        for (int i = 0; i < n; i++) {
            data[i] = new Edge();
            data[i].s = scanner.next(); // Read string
            data[i].p = scanner.nextLong(); // Read weight
            data[i].i = i; // Store the original index
        }
        
        // Sort the edges based on the defined sorting criteria
        Arrays.sort(data, 0, n, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                // First compare by string identifier
                int cmp = a.s.compareTo(b.s);
                if (cmp != 0) return cmp;
                // If identifiers are the same, compare by weight in descending order
                if (a.p < b.p) return 1;
                return -1;
            }
        });
        
        // Output the original indices of the sorted edges
        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }
    }
    
    // Define a class to hold edge information
    static class Edge {
        long p; // Weight or value associated with the edge
        int i; // Index of the edge
        String s; // Name or identifier of the edge
    }
}
