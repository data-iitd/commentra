
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        int w = in.nextInt();
        in.nextLine();

        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = in.nextLine();
            for (int j = 0; j < w; j++) {
                if (s.charAt(j) == '#') {
                    graph[i][j] = Integer.MAX_VALUE;
                } else {
                    graph[i][j] = 0;
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

        // Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                max = Math.max(max, graph[i][j]);
            }
        }
        System.out.println(max);
    }
}

