
import java.util.Scanner;

public class atcoder_ABC167_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
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
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < n; k++) {
                    int ca = 0;
                    for (int ii = 0; ii < j; ii++) {
                        ca += c[l[k][ii]][i];
                    }
                    if (ca < x) {
                        rem[k][count] = j;
                    } else {
                        l[k][j] = l[k][j - 1];
                    }
                }
                if (rem[0][count]!= 0) {
                    for (int k = 0; k < n; k++) {
                        l[k][rem[k][count]] = 0;
                    }
                }
                count++;
                if (rem[0][count - 1] == 0) {
                    break;
                }
            }
            if (rem[0][count - 1] == 0) {
                break;
            }
        }
        if (rem[0][count - 1] == 0) {
            for (int i = 0; i < n; i++) {
                int ca = 0;
                for (int j = 0; j < n; j++) {
                    if (l[i][j]!= 0) {
                        ca += c[l[i][j] - 1][0];
                    }
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = Math.min(ans, ca);
                }
            }
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}
