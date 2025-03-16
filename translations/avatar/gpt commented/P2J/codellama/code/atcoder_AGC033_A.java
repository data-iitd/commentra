
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
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        for (int x = w - 1; x >= 0; x--) {
            for (int y = 0; y < h; y++) {
                graph[y][x] = Math.min(graph[y][x], graph[y][x + 1] + 1);
            }
        }

        for (int x = w - 1; x >= 0; x--) {
            for (int y = 0; y < h; y++) {
                graph[y][x] = Math.min(graph[y][x], graph[y + 1][x] + 1);
            }
        }

        for (int y = h - 1; y >= 0; y--) {
            for (int x = 0; x < w; x++) {
                graph[y][x] = Math.min(graph[y][x], graph[y - 1][x] + 1);
            }
        }

        for (int y = h - 1; y >= 0; y--) {
            for (int x = 0; x < w; x++) {
                graph[y][x] = Math.min(graph[y][x], graph[y][x - 1] + 1);
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

