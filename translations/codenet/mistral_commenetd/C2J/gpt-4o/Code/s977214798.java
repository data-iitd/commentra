import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a = new int[1000][999];
    static int[] e1 = new int[1000000];
    static int[] e2 = new int[1000000];
    static int[] d = new int[1000000];
    static boolean[] b = new boolean[1000000];

    // Function to read an integer from standard input
    static int nextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Function to calculate the result of the given expression p(a, b)
    static int p(int a, int b) {
        // Check if a is smaller than b
        if (a < b) {
            return a + b * n;
        } else {
            return b + a * n;
        }
    }

    // Function to perform Depth First Search (DFS) from a given vertex 'from'
    static int f(int from) {
        // Check if vertex 'from' has already been visited
        if (b[from]) return -1;
        // If vertex 'from' has already been processed, return its depth
        if (d[from] != 0) return d[from];
        // Mark vertex 'from' as visited
        b[from] = true;
        // Initialize maximum depth as 0
        int max = 0;
        // Traverse to the adjacent vertices of 'from'
        int to;
        to = e1[from];
        // If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
        if (to != 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        // Traverse to the next adjacent vertex of 'from'
        to = e2[from];
        // If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
        if (to != 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        // Mark vertex 'from' as not visited
        b[from] = false;
        // Update the depth of vertex 'from' with the maximum depth found during DFS
        return d[from] = max + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of vertices n from standard input
        n = nextInt(scanner);
        // Initialize 2D array a of size n x (n-1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                // Read an edge weight from standard input and store it in the corresponding position of array a
                a[i][j] = nextInt(scanner) - 1;
            }
        }
        // Initialize arrays e1, e2 and d with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                // Read an edge from standard input and store it in the corresponding position of arrays e1 or e2 based on its direction
                int from = p(i, a[i][j]);
                int to = p(i, a[i][j + 1]);
                if (e1[from] == 0) {
                    e1[from] = to;
                } else if (e2[from] == 0) {
                    e2[from] = to;
                } else {
                    // If there is a cycle in the graph, print '-1' and exit the program
                    System.out.println("-1");
                    return;
                }
            }
        }
        // Initialize an empty stack or array to store the vertices in Depth First Search order
        int ans = 0;
        // Perform Depth First Search from each vertex and update the answer with the maximum depth found
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]);
            int now = f(from);
            if (now < 0) {
                ans = -1;
                break;
            }
            if (now > ans) ans = now;
        }
        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
