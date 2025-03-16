
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] cnt = new int[10][10];
        for (int i = 1; i <= n; i++) {
            int a = i % 10;
            int b = i;
            while (b >= 10) {
                b /= 10;
            }
            cnt[b][a]++;
        }
        long ans = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                ans += cnt[i][j] * cnt[j][i];
            }
        }
        System.out.println(ans);
    }
}

