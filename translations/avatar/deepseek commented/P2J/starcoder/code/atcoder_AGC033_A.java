
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = sc.next();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') {
                    graph[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        for (int i = 0; i < w - 1; i++) {
            for (int j = 0; j < h; j++) {
                graph[j][i + 1] = Math.min(graph[j][i] + 1, graph[j][i + 1]);
            }
        }
        for (int i = w - 1; i > 0; i--) {
            for (int j = 0; j < h; j++) {
                graph[j][i - 1] = Math.min(graph[j][i] + 1, graph[j][i - 1]);
            }
        }
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w; j++) {
                graph[i + 1][j] = Math.min(graph[i][j] + 1, graph[i + 1][j]);
            }
        }
        for (int i = h - 1; i > 0; i--) {
            for (int j = 0; j < w; j++) {
                graph[i - 1][j] = Math.min(graph[i][j] + 1, graph[i - 1][j]);
            }
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                max = Math.max(max, graph[i][j]);
            }
        }
        System.out.println(max);
    }
}

