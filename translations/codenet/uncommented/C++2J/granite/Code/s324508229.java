
import java.util.*;
import java.io.*;

class s324508229 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] cnt = new long[10][10];
        for (int i = 1; i <= n; i++) {
            int b = i % 10;
            int a = i;
            while (a >= 10) {
                a /= 10;
            }
            cnt[a][b]++;
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

