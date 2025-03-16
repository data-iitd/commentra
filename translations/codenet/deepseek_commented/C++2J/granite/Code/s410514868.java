
import java.util.*;

public class s410514868{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        String s = sc.next();
        char[] c = s.toCharArray();
        long ans = 0;
        long L = c[0];
        long cnt = 0;
        for (int i = 1; i < n; i++) {
            if (L == c[i]) {
                cnt++;
            } else {
                L = c[i];
                ans += cnt;
                cnt = 0;
            }
        }
        ans += cnt;
        System.out.println(ans + Math.min(2 * k, n - 1));
    }
}

