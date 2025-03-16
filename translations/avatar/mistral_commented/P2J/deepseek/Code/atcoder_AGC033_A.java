import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input dimensions of the graph
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        // Initializing the graph as a 2D array with initial values
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                graph[i][j] = line.charAt(j) == '#' ? 0 : Integer.MAX_VALUE;
            }
        }
        
        // Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
            }
        }
        
        // Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
            }
        }
        
        // Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
            }
        }
        
        // Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
            }
        }
        
        // Finding and printing the maximum shortest path distance in the graph
        int maxDistance = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                maxDistance = Math.max(maxDistance, graph[y][x]);
            }
        }
        System.out.println(maxDistance);
    }
}
