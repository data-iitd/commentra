import java.util.*;

public class Main {
    static int n, k;
    static int[] aaa;
    static List<Set<Integer>> links;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        aaa = new int[n];
        for (int i = 0; i < n; i++) {
            aaa[i] = scanner.nextInt();
        }
        links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            a--;
            links.get(a).add(i + 1);
        }
        int ans = dfs(0, 0) + (aaa[0] != 1 ? 1 : 0);
        System.out.println(ans);
    }

    static int dfs(int v, int p) {
        int heightFromLeaf = 0;
        int cutCount = 0;
        for (int u : links.get(v)) {
            if (u == 0) {
                continue;
            }
            int[] result = dfs(u, v);
            heightFromLeaf = Math.max(heightFromLeaf, result[0]);
            cutCount += result[1];
        }
        heightFromLeaf++;
        if (p != 0 && heightFromLeaf == k) {
            heightFromLeaf = 0;
            cutCount++;
        }
        return new int[]{heightFromLeaf, cutCount};
    }
}
