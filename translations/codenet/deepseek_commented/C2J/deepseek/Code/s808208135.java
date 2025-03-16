import java.util.*;

class Main {
    static final int N = 100000;
    static final int INF = 1000000;

    // Define a class to store connection details
    static class Date {
        int go, back, cost;

        Date(int go, int back, int cost) {
            this.go = go;
            this.back = back;
            this.cost = cost;
        }
    }

    // Define the maximum number of nodes and the distance array
    static int n;
    static int[] d = new int[N];
    static List<Date>[] a = new ArrayList[500000];

    // Declare the root function
    static void root(int b);

    public static void main(String[] args) {
        // Declare variables for iteration and input
        int i, j, k, u, count = 0;

        // Read the number of nodes
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Initialize the array of lists
        for (i = 0; i < 500000; i++) {
            a[i] = new ArrayList<>();
        }

        // Read each node's connections and store them in the array 'a'
        for (i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            for (j = 0; j < k; j++) {
                int go = scanner.nextInt();
                int cost = scanner.nextInt();
                a[count].add(new Date(go, u, cost));
                count++;
            }
        }

        // Call the root function to initialize distances
        root(count);

        // Print the shortest distances from the root node to each node
        for (i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }

    // Function to initialize distances and update them based on connections
    static void root(int b) {
        int i, flag = 1;

        // Initialize all distances to INF except the root node (node 0)
        for (i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[0] = 0;

        // Use a while loop to update distances based on connections
        while (flag != 0) {
            flag = 0;
            for (i = 0; i < b; i++) {
                for (Date date : a[i]) {
                    if (date.cost + d[date.back] < d[date.go]) {
                        d[date.go] = date.cost + d[date.back];
                        flag = 1;
                    }
                }
            }
        }
    }
}
