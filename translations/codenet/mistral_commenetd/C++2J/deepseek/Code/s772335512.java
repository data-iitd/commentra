import java.util.*;

public class Main {
    static List<Integer>[] G = new ArrayList[100000];
    static boolean[] used = new boolean[100000];
    static int[] grundy = new int[100000];

    static void dfs(int v) {
        used[v] = true;
        grundy[v] = 0;
        for (int w : G[v]) {
            if (!used[w]) {
                dfs(w);
                grundy[v] ^= (grundy[w] + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            G[x].add(y);
            G[y].add(x);
        }
        dfs(0);
        if (grundy[0] != 0) {
            System.out.println("Alice");
        } else {
            System.out.println("Bob");
        }
    }
}
