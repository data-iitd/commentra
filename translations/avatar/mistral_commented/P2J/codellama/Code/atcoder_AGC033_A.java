
import java.util.Scanner;
import java.util.Arrays;

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
                graph[i][j] = s.charAt(j) == '#' ? 0 : Integer.MAX_VALUE;
            }
        }

        for (int x = 0; x < w - 1; x++) {
            for (int i = 0; i < h; i++) {
                graph[i][x + 1] = Math.min(graph[i][x] + 1, graph[i][x + 1]);
            }
        }

        for (int x = w - 1; x > 0; x--) {
            for (int i = 0; i < h; i++) {
                graph[i][x - 1] = Math.min(graph[i][x] + 1, graph[i][x - 1]);
            }
        }

        for (int y = 0; y < h - 1; y++) {
            for (int i = 0; i < w; i++) {
                graph[y + 1][i] = Math.min(graph[y][i] + 1, graph[y + 1][i]);
            }
        }

        for (int y = h - 1; y > 0; y--) {
            for (int i = 0; i < w; i++) {
                graph[y - 1][i] = Math.min(graph[y][i] + 1, graph[y - 1][i]);
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

