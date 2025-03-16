import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ta = scanner.nextInt() - 1;
        int ao = scanner.nextInt() - 1;

        List<List<Integer>> g = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }

        int[] taDist = new int[n];
        Arrays.fill(taDist, -1);
        taDist[ta] = 0;

        int[] aoDist = new int[n];
        Arrays.fill(aoDist, -1);
        aoDist[ao] = 0;

        dfs(ta, g, taDist);
        dfs(ao, g, aoDist);

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (taDist[i] <= aoDist[i]) {
                res = Math.max(res, aoDist[i]);
            }
        }

        System.out.println(res - 1);
    }

    private static void dfs(int start, List<List<Integer>> g, int[] dist) {
        Stack<Integer> stack = new Stack<>();
        stack.push(start);

        while (!stack.isEmpty()) {
            int node = stack.pop();
            for (int neighbor : g.get(node)) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    stack.push(neighbor);
                }
            }
        }
    }
}
