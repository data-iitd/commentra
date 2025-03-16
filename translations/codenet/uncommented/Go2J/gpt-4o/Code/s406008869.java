import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static List<List<Integer>> e;
    static int n, m;

    public static void printEdge(List<List<Integer>> e) {
        for (int i = 1; i <= n; i++) {
            System.out.print(i + ": ");
            for (int v : e.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    public static int dfs(int v, boolean[] visited) {
        boolean comp = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                comp = false;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int ne : e.get(v)) {
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true;
            int rst = dfs(ne, visited);
            count += rst;
            visited[ne] = false;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        e = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            e.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            e.get(a).add(b);
            e.get(b).add(a);
        }
        // printEdge(e);

        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }
}

// <END-OF-CODE>
