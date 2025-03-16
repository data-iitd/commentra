
import java.util.*;

public class s814769071{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int MOD = 100000007;
        long mx = (long)n * (n + 1) / 2 - (long)(n - k) * (n - k + 1) / 2;
        long mn = (long)k * (k - 1) / 2;
        long res = 0;
        for (int i = k; i <= n + 1; ++i) {
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
            res %= MOD;
        }
        System.out.println(res);
    }
}

