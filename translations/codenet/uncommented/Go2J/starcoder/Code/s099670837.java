import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        int ans = 0;
        findAns(0, 0, 0, n, a, ans);
        System.out.println(ans);
    }

    public static void findAns(int i, int j, int sum, int n, int[][] a, int ans) {
        if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
            ans = sum + a[i][j];
            return;
        }
        if (i == 0) {
            findAns(i + 1, j, sum + a[i][j], n, a, ans);
        }
        if (j + 1 < n) {
            findAns(i, j + 1, sum + a[i][j], n, a, ans);
        }
    }
}

