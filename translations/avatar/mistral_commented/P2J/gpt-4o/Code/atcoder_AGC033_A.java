import java.util.Scanner;

public class DijkstraGraph {
    public static void main(String[] args) {
        // Importing the Scanner class for input
        Scanner scanner = new Scanner(System.in);

        // Taking input dimensions of the graph
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Initializing the graph as a 2D array with initial values
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') {
                    graph[i][j] = Integer.MAX_VALUE; // Use a large value to represent infinity
                } else {
                    graph[i][j] = 0; // Initial value for empty cells
                }
            }
        }

        // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x] != Integer.MAX_VALUE) {
                    graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
                }
            }
        }

        // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x] != Integer.MAX_VALUE) {
                    graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
                }
            }
        }

        // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != Integer.MAX_VALUE) {
                    graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
                }
            }
        }

        // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != Integer.MAX_VALUE) {
                    graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
                }
            }
        }

        // Finding the maximum shortest path distance in the graph
        int maxDistance = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] != Integer.MAX_VALUE) {
                    maxDistance = Math.max(maxDistance, graph[i][j]);
                }
            }
        }

        // Printing the maximum shortest path distance in the graph
        System.out.println(maxDistance);

        scanner.close();
    }
}
// <END-OF-CODE>
