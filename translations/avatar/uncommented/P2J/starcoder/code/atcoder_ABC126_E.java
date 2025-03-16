import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int[][] edge = new int[N][N];
        for (int i = 0; i < M; i++) {
            int X = in.nextInt() - 1;
            int Y = in.nextInt() - 1;
            int Z = in.nextInt();
            edge[X][Y] = Z;
            edge[Y][X] = Z;
        }
        int ans = 0;
        boolean[] used = new boolean[N];
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                ans++;
                Queue<Integer> queue = new LinkedList<Integer>();
                queue.add(i);
                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    used[node] = true;
                    for (int nextnode : edge[node]) {
                        if (!used[nextnode]) {
                            queue.add(nextnode);
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
