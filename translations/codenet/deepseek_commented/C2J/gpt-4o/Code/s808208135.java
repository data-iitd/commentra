import java.util.Scanner;

class Connection {
    int go, back, cost;

    public Connection(int back, int go, int cost) {
        this.back = back;
        this.go = go;
        this.cost = cost;
    }
}

public class ShortestPath {
    static final int N = 100000;
    static final int INF = 1000000;
    static int n;
    static int[] d = new int[N];
    static Connection[] a = new Connection[500000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;

        // Read the number of nodes
        n = scanner.nextInt();

        // Read each node's connections and store them in the array 'a'
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt();
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int go = scanner.nextInt();
                int cost = scanner.nextInt();
                a[count++] = new Connection(u, go, cost);
            }
        }

        // Call the root function to initialize distances
        root(count);

        // Print the shortest distances from the root node to each node
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }

        scanner.close();
    }

    // Function to initialize distances and update them based on connections
    static void root(int b) {
        // Initialize all distances to INF except the root node (node 0)
        for (int i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[0] = 0;

        // Use a while loop to update distances based on connections
        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < b; i++) {
                if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = true;
                }
            }
        }
    }
}

// <END-OF-CODE>
