import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int x = Integer.parseInt(input[2]);

        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            String[] row = scanner.nextLine().split(" ");
            for (int j = 0; j <= m; j++) {
                c[i][j] = Integer.parseInt(row[j]);
            }
        }

        int ans = -1;
        for (int i = 1; i < (1 << n); i++) {
            int[] cost = new int[m + 1];
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    for (int k = 0; k <= m; k++) {
                        cost[k] += c[j][k];
                    }
                }
            }
            boolean valid = true;
            for (int j = 1; j <= m; j++) {
                if (cost[j] < x) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                int totalCost = cost[0];
                if (ans == -1 || totalCost < ans) {
                    ans = totalCost;
                }
            }
        }

        System.out.println(ans);
    }
}
