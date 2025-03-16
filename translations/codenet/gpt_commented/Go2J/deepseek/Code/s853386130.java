import java.util.*;

public class Main {
    static final int mod = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int R = scanner.nextInt();

        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1;
        }

        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], INF);
            costs[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            costs[a][b] = c;
            costs[b][a] = c;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        List<List<Integer>> perms = permutations(rs);
        int ans = INF;

        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }

        System.out.println(ans);
    }

    public static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();
        permute(arr, 0, result);
        return result;
    }

    private static void permute(int[] arr, int start, List<List<Integer>> result) {
        if (start == arr.length - 1) {
            List<Integer> tempList = new ArrayList<>();
            for (int num : arr) {
                tempList.add(num);
            }
            result.add(tempList);
        } else {
            for (int i = start; i < arr.length; i++) {
                swap(arr, start, i);
                permute(arr, start + 1, result);
                swap(arr, start, i); // backtrack
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
