public class Main {
    static final int MAX = 100000;
    static final int[] grundy = new int[MAX];
    static final boolean[] used = new boolean[MAX];
    static final java.util.List<Integer>[] G = new java.util.ArrayList[MAX];

    static void dfs(int v) {
        used[v] = true;
        grundy[v] = 0;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v].get(i)]) {
                dfs(G[v].get(i));
                grundy[v] ^= (grundy[G[v].get(i)] + 1);
            }
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        for (int i = 0; i < MAX; i++) {
            G[i] = new java.util.ArrayList<>();
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
