import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                c[i][j] = scanner.nextInt();
            }
        }
        
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int[] indices = new int[i];
            generateCombinations(indices, 0, n, i, l);
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < l.size(); j++) {
                List<Integer> k = l.get(j);
                int ca = 0;
                for (int ii : k) {
                    ca += c[ii][i];
                }
                if (ca < x) {
                    rem.add(0, j);
                }
            }
            if (!rem.isEmpty()) {
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();
            }
            if (l.isEmpty()) {
                System.out.println(-1);
                return;
            }
        }
        
        for (List<Integer> i : l) {
            int ca = 0;
            for (int j : i) {
                ca += c[j][0];
            }
            if (ans == 0) {
                ans = ca;
            } else {
                ans = Math.min(ans, ca);
            }
        }
        System.out.println(ans);
    }

    private static void generateCombinations(int[] indices, int start, int n, int r, List<List<Integer>> result) {
        if (r == 0) {
            List<Integer> combination = new ArrayList<>();
            for (int index : indices) {
                combination.add(index);
            }
            result.add(combination);
            return;
        }
        for (int i = start; i <= n - r; i++) {
            indices[indices.length - r] = i;
            generateCombinations(indices, i + 1, n, r - 1, result);
        }
    }
}
