import java.util.Scanner;

public class GraphDistance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the height (h) and width (w) of the graph from input
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Initialize the graph: 
        // Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') {
                    graph[i][j] = 0; // Obstacle
                } else {
                    graph[i][j] = Integer.MAX_VALUE; // Unvisited cells
                }
            }
        }

        // Update the graph by calculating the minimum distance from the left side
        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }

        // Update the graph by calculating the minimum distance from the right side
        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }

        // Update the graph by calculating the minimum distance from the top side
        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }

        // Update the graph by calculating the minimum distance from the bottom side
        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }

        // Find the maximum distance found in the graph, which represents the farthest distance from an obstacle
        int maxDistance = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                maxDistance = Math.max(maxDistance, graph[i][j]);
            }
        }

        // Print the maximum distance
        System.out.println(maxDistance);
        
        scanner.close();
    }
}
// <END-OF-CODE>
