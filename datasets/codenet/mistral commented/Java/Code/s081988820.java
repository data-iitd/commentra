import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        // Initialize Main object and call its solve method
        Main main = new Main();
        main.solve();
    }

    private void solve() {
        // Initialize Scanner object to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read input: height H and width W of the grid
        int H = sc.nextInt();
        int W = sc.nextInt();

        // Initialize 2D integer array 'c' to store the cost of each cell in the grid
        int[][] c = new int[10][10];

        // Read input: cost of each cell in the grid
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        // Initialize an array 'min' to store the minimum cost to reach each cell from the top-left corner
        int[] min = new int[10];

        // Calculate the minimum cost to reach each cell from the top-left corner using dynamic programming
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    // Calculate the minimum cost to reach the current cell (i, j)
                    min[i] = Math.min(min[i], c[i][j] + min[j]);
                }
            }
        }

        // Initialize variable 'ans' to store the answer
        int ans = 0;

        // Read input: queries (A, h, w) and calculate the answer for each query
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A = sc.nextInt();
                if (A >= 0) {
                    // If A is a valid index, add the minimum cost to reach that index to the answer
                    ans += min[A];
                }
            }
        }

        // Print the answer
        System.out.println(ans);

        // Close the Scanner to release system resources
        sc.close();
    }

    // Define a custom Scanner class to read input efficiently
    class Scanner {
        // ... (The rest of the Scanner class remains the same)
    }
}
