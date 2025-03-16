
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int[][] graph = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = sc.next();
            for (int j = 0; j < w; j++) {
                if (s.charAt(j) == '#') {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w - 1; j++) {
                graph[i][j] = Math.min(graph[i][j] + 1, graph[i][j + 1]);
            }
        }
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w; j++) {
                graph[i][j] = Math.min(graph[i][j] + 1, graph[i + 1][j]);
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                System.out.print(graph[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println(Arrays.stream(graph).mapToInt(x -> Arrays.stream(x).max().getAsInt()).max().getAsInt());
    }
}

