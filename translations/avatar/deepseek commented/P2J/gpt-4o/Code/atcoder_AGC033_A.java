import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the dimensions of the grid
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Initialize the grid with 0 for '#' and Integer.MAX_VALUE for '.'
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        // Processing in the left to right direction
        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }

        // Processing in the right to left direction
        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }

        // Processing in the top to bottom direction
        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }

        // Processing in the bottom to top direction
        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }

        // Find the maximum value in the grid, which represents the maximum distance to the nearest '#'
        int maxDistance = 0;
        for (int[] row : graph) {
            for (int value : row) {
                maxDistance = Math.max(maxDistance, value);
            }
        }

        // Print the result
        System.out.println(maxDistance);
    }
}
// <END-OF-CODE>
