import java.util.*;

public class Main {
    static int n;
    static int[][] a = new int[1000][999];
    static int[] e1 = new int[1000000];
    static int[] e2 = new int[1000000];
    static int[] d = new int[1000000];
    static boolean[] b = new boolean[1000000];

    static int p(int a, int b) {
        if (a < b) {
            return a + b * n;
        } else {
            return b + a * n;
        }
    }

    static int f(int from) {
        if (b[from]) return -1; // If node is already visited, return -1 indicating a cycle
        if (d[from] != 0) return d[from]; // If distance is already calculated, return it
        b[from] = true; // Mark the node as visited
        int to;
        to = e1[from];
        int max = 0;
        if (to != 0) {
            int now = f(to); // Recursively find the longest path from 'to'
            if (now < 0) return now; // If there's a cycle, return -1
            if (now > max) max = now; // Update max if a longer path is found
        }
        to = e2[from];
        if (to != 0) {
            int now = f(to); // Recursively find the longest path from 'to'
            if (now < 0) return now; // If there's a cycle, return -1
            if (now > max) max = now; // Update max if a longer path is found
        }
        b[from] = false; // Unmark the node as visited (backtracking)
        return d[from] = max + 1; // Store and return the longest path length
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the size of the problem
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                a[i][j] = scanner.nextInt() - 1; // Read and adjust indices to be 0-based
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                int from = p(i, a[i][j]); // Create a unique node index 'from'
                int to = p(i, a[i][j + 1]); // Create a unique node index 'to'
                if (e1[from] == 0) {
                    e1[from] = to; // Assign 'to' to e1 of 'from'
                } else if (e2[from] == 0) {
                    e2[from] = to; // Assign 'to' to e2 of 'from'
                } else {
                    System.out.println(-1); // If both e1 and e2 are already assigned, print -1 and exit
                    return;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]); // Create a unique starting node index 'from'
            int now = f(from); // Find the longest path from 'from'
            if (now < 0) {
                ans = -1; // If there's a cycle, set ans to -1
                break;
            }
            if (now > ans) ans = now; // Update ans if a longer path is found
        }
        System.out.println(ans); // Print the result
    }
}
