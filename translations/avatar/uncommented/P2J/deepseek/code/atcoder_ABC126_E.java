import java.util.*;

public class Main {
    static int N, M;
    static List<List<Integer>> edge = new ArrayList<>();
    static boolean[] used;
    static int ans;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int X = scanner.nextInt() - 1;
            int Y = scanner.nextInt() - 1;
            int Z = scanner.nextInt() - 1;
            edge.get(X).add(Y);
            edge.get(Y).add(X);
        }
        used = new boolean[N];
        ans = 0;
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                ans++;
                Queue<Integer> queue = new LinkedList<>();
                queue.add(i);
                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    used[node] = true;
                    for (int nextnode : edge.get(node)) {
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
