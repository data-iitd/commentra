
import java.util.Scanner;

public class s099670837{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] a = new int[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
        int ans = 0;
        findAns(a, 0, 0, 0);
        System.out.println(ans);
    }

    public static void findAns(int[][] a, int i, int j, int sum) {
        if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
            ans = sum + a[i][j];
            return;
        }
        if (i == 0) {
            findAns(a, i + 1, j, sum + a[i][j]);
        }
        if (j + 1 < n) {
            findAns(a, i, j + 1, sum + a[i][j]);
        }
    }
}

