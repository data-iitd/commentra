import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the height (h) and width (w) of the graph from input
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Initialize the graph
        int[][] graph = new int[h][w];
        
        // Read the graph from input
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') {
                    graph[i][j] = 0; // Obstacle
                } else {
                    graph[i][j] = Integer.MAX_VALUE; // Unvisited cell
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
        
        // Find the maximum distance found in the graph
        int maxDistance = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != 0) { // Exclude obstacles
                    maxDistance = Math.max(maxDistance, graph[y][x]);
                }
            }
        }
        
        // Print the maximum distance
        System.out.println(maxDistance);
    }
}
