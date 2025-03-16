import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the dimensions of the grid
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        // Initialize the grid with 0 for '.' and Integer.MAX_VALUE for '#'
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                graph[i][j] = (line.charAt(j) == '#') ? Integer.MAX_VALUE : 0;
            }
        }

        // Calculate the minimum distance to any '#' for each cell in the grid
        // Processing in the left to right direction
        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x + 1] != Integer.MAX_VALUE) {
                    graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
                }
            }
        }

        // Processing in the right to left direction
        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x - 1] != Integer.MAX_VALUE) {
                    graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
                }
            }
        }

        // Processing in the top to bottom direction
        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                if (graph[y + 1][x] != Integer.MAX_VALUE) {
                    graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
                }
            }
        }

        // Processing in the bottom to top direction
        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                if (graph[y - 1][x] != Integer.MAX_VALUE) {
                    graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
                }
            }
        }

        // Find the maximum value in the grid, which represents the maximum distance to the nearest '#'
        int maxDistance = 0;
        for (int[] row : graph) {
            for (int value : row) {
                if (value != Integer.MAX_VALUE) {
                    maxDistance = Math.max(maxDistance, value);
                }
            }
        }

        // Print the maximum value in the grid
        System.out.println(maxDistance);
    }
}
