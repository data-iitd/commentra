import java.io.*;
import java.util.*;

public class Main {
    private static final int BLACK = 35; // Define a constant for the black color
    private static final int INF = 1000000007;
    private static final int INF2 = 1000000009;
    private static final int INF3 = 998244353;

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        try {
            String[] firstLine = reader.readLine().split(" ");
            int h = Integer.parseInt(firstLine[0]);
            int w = Integer.parseInt(firstLine[1]);
            int k = Integer.parseInt(firstLine[2]);

            int[][] m = new int[h][w]; // Create a 2D array for the grid
            for (int i = 0; i < h; i++) {
                String s = reader.readLine(); // Read the row as a string
                for (int j = 0; j < w; j++) {
                    m[i][j] = (int) s.charAt(j); // Convert each character to int and store
                }
            }

            int answer = solve(h, w, k, m); // Solve the problem and get the answer
            writer.println(answer); // Print the answer
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            writer.flush();
            writer.close();
        }
    }

    // countBlack counts the number of black cells in the grid.
    private static int countBlack(int h, int w, int[][] m) {
        int count = 0; // Initialize count
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == BLACK) {
                    count++; // Increment count if the cell is black
                }
            }
        }
        return count; // Return the count of black cells
    }

    // solve calculates the number of ways to paint the grid to achieve the target count of black cells.
    private static int solve(int h, int w, int a, int[][] m) {
        int result = 0; // Initialize result
        for (int i = 0; i < (1 << h); i++) { // Iterate over all possible row paint combinations
            for (int k = 0; k < (1 << w); k++) { // Iterate over all possible column paint combinations
                int[][] tmp = new int[h][w]; // Create a temporary grid to simulate painting
                for (int j = 0; j < h; j++) {
                    System.arraycopy(m[j], 0, tmp[j], 0, w); // Copy original grid to temporary grid
                }
                // Paint rows based on the current combination
                for (int j = 0; j < h; j++) {
                    if ((1 << j & i) > 0) { // Check if the current row is painted
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1; // Paint the entire row
                        }
                    }
                }
                // Paint columns based on the current combination
                for (int j = 0; j < w; j++) {
                    if ((1 << j & k) > 0) { // Check if the current column is painted
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1; // Paint the entire column
                        }
                    }
                }
                if (countBlack(h, w, tmp) == a) { // Check if the count of black cells matches the target
                    result++; // Increment result if it matches
                }
            }
        }
        return result; // Return the total number of valid combinations
    }
}
// <END-OF-CODE>
