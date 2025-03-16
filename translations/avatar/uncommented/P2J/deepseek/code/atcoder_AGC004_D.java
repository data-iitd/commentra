import java.util.*;

public class Main {
    static int n, k;
    static List<Set<Integer>> links;
    static int[] aaa;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        aaa = new int[n];
        for (int i = 0; i < n; i++) {
            aaa[i] = scanner.nextInt();
        }
        scanner.close();

        links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }
        for (int i = 1; i < n; i++) {
            int a = aaa[i] - 1;
            links.get(a).add(i);
        }

        int[] result = dfs(0, 0);
        if (aaa[0] != 1) {
            result[1]++;
        }
        System.out.println(result[1]);
    }

    static int[] dfs(int v, int p) {
        int heightFromLeaf = 0;
        int cutCount = 0;
        for (int u : links.get(v)) {
            if (u == 0) {
                continue;
            }
            int[] hgtCut = dfs(u, v);
            heightFromLeaf = Math.max(heightFromLeaf, hgtCut[0]);
            cutCount += hgtCut[1];
        }
        heightFromLeaf += 1;
        if (p != 0 && heightFromLeaf == k) {
            heightFromLeaf = 0;
            cutCount++;
        }
        return new int[]{heightFromLeaf, cutCount};
    }
}
