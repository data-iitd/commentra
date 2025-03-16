
import java.util.Scanner;

public class atcoder_ABC167_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        int[][] l = new int[n][n];
        int[][] rem = new int[n][n];
        int ans = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < count; j++) {
                for (int k = 0; k < i; k++) {
                    l[j][k] = rem[j][k];
                }
            }
            for (int j = 0; j < count; j++) {
                int ca = 0;
                for (int k = 0; k < i; k++) {
                    ca += c[l[j][k]][i - 1];
                }
                if (ca < x) {
                    for (int k = 0; k < i; k++) {
                        rem[count][k] = l[j][k];
                    }
                    count++;
                }
            }
            if (count == 0) {
                System.out.println(-1);
                break;
            }
            for (int j = 0; j < count; j++) {
                int ca = 0;
                for (int k = 0; k < i; k++) {
                    ca += c[rem[j][k]][0];
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = Math.min(ans, ca);
                }
            }
        }
        System.out.println(ans);
    }
}
