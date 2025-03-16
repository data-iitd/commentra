import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int[][] graph = new int[h][w];

        for (int y = 0; y < h; y++) {
            String line = scanner.next();
            for (int x = 0; x < w; x++) {
                if (line.charAt(x) == '#') {
                    graph[y][x] = 0;
                } else {
                    graph[y][x] = Integer.MAX_VALUE;
                }
            }
        }

        for (int x = 0; x < w - 1; x++) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x] != 0) {
                    graph[y][x + 1] = Math.min(graph[y][x] + 1, graph[y][x + 1]);
                }
            }
        }

        for (int x = w - 1; x > 0; x--) {
            for (int y = 0; y < h; y++) {
                if (graph[y][x] != 0) {
                    graph[y][x - 1] = Math.min(graph[y][x] + 1, graph[y][x - 1]);
                }
            }
        }

        for (int y = 0; y < h - 1; y++) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != 0) {
                    graph[y + 1][x] = Math.min(graph[y][x] + 1, graph[y + 1][x]);
                }
            }
        }

        for (int y = h - 1; y > 0; y--) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != 0) {
                    graph[y - 1][x] = Math.min(graph[y][x] + 1, graph[y - 1][x]);
                }
            }
        }

        int maxDistance = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (graph[y][x] != 0 && graph[y][x] != Integer.MAX_VALUE) {
                    maxDistance = Math.max(maxDistance, graph[y][x]);
                }
            }
        }

        System.out.println(maxDistance);
    }
}
