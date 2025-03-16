import java.util.Scanner;

class Date {
    int go, back, cost;

    Date(int back, int go, int cost) {
        this.back = back;
        this.go = go;
        this.cost = cost;
    }
}

public class Dijkstra {
    static final int N = 100000;
    static final int INF = 1000000;
    static int n;
    static int[] d = new int[N];
    static Date[] a = new Date[500000]; // Array to store the adjacency list and cost for each edge

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0; // Variable to keep track of the number of edges

        n = scanner.nextInt(); // Read the number of vertices

        for (int i = 0; i < n; i++) { // Iterate through each vertex
            int u = scanner.nextInt();
            int k = scanner.nextInt(); // Read the number of edges and their destinations

            for (int j = 0; j < k; j++) { // Iterate through each edge
                int go = scanner.nextInt();
                int cost = scanner.nextInt();
                a[count++] = new Date(u, go, cost); // Store the edge
            }
        }

        root(count); // Call the Dijkstra's algorithm function

        for (int i = 0; i < n; i++) // Print the shortest distance from the source to each vertex
            System.out.println(i + " " + d[i]);

        scanner.close();
    }

    static void root(int b) {
        for (int i = 0; i < n; i++) // Initialize the shortest distance array with infinite values
            d[i] = INF;

        d[0] = 0; // Set the shortest distance to the source vertex to 0

        boolean flag = true; // While there are still vertices with updated shortest distances

        while (flag) {
            flag = false; // Assume no vertices have updated shortest distances

            for (int i = 0; i < b; i++) { // Iterate through all the edges
                if (a[i].cost + d[a[i].back] < d[a[i].go]) { // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
                    d[a[i].go] = a[i].cost + d[a[i].back]; // Update the shortest distance to the current vertex
                    flag = true; // Set the flag to indicate that there are still vertices with updated shortest distances
                }
            }
        }
    }
}

// <END-OF-CODE>
