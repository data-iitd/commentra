import java.util.*;

public class Prim {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] graph = new int[n][n];
        int[] distance = new int[n];
        int[] parent = new int[n];
        int[] color = new int[n];
        int min, u, v, sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;
            color[i] = 0;
        }

        distance[0] = 0;

        while (true) {
            min = Integer.MAX_VALUE;
            u = -1;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0 && distance[i] < min) {
                    min = distance[i];
                    u = i;
                }
            }
            if (u == -1) {
                break;
            }
            color[u] = 1;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0 && graph[u][i]!= Integer.MAX_VALUE) {
                    if (distance[i] > graph[u][i]) {
                        distance[i] = graph[u][i];
                        parent[i] = u;
                        color[i] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (parent[i]!= -1) {
                sum += graph[i][parent[i]];
            }
        }
        System.out.println(sum);
    }
}

