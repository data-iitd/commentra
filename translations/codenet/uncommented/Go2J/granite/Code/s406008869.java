
import java.util.Scanner;

public class s406008869{
    static int[][] e;
    static int n, m;

    static void printEdge(int[][] e) {
        for (int i = 1; i < n + 1; i++) {
            System.out.printf("%d: ", i);
            for (int v : e[i]) {
                System.out.printf("%d ", v);
            }
            System.out.println();
        }
    }

    static int dfs(int v, boolean[] visited) {
        // visited[v] = true;
        // System.out.println(v + " " + Arrays.toString(visited));

        boolean comp = true;
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]) {
                comp = false;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int ne : e[v]) {
            // System.out.printf("ne=%d\n", ne);
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true;
            // if (cmp) {
            //     count++;
            // }
            int rst = dfs(ne, visited);
            // System.out.println(rst);
            // count += dfs(ne, visited);
            count += rst;
            visited[ne] = false;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        e = new int[n + 1][];
        for (int i = 1; i < n + 1; i++) {
            e[i] = new int[0];
        }
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            e[a] = ArrayUtils.add(e[a], b);
            e[b] = ArrayUtils.add(e[b], a);
        }
        // printEdge(e);

        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }
}

