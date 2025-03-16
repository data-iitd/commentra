public class Main {
    public static void main(String[] args) {
        // Read the number of edges
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Array to hold edge data
        Edge[] data = new Edge[100];

        // Read each edge's string and long long value, and store the index
        for (int i = 0; i < n; i++) {
            data[i] = new Edge();
            data[i].s = scanner.next();
            data[i].p = scanner.nextLong();
            data[i].i = i;
        }

        // Sort the edges using Arrays.sort and the custom esort function
        Arrays.sort(data, 0, n, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                int cmp = a.s.compareTo(b.s);
                if (cmp != 0) return cmp;
                if (a.p < b.p) return 1;
                return -1;
            }
        });

        // Print the indices of the edges in the sorted order
        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }
    }

    // Define a structure to hold edge information
    static class Edge {
        String s;
        long p;
        int i;
    }
}
