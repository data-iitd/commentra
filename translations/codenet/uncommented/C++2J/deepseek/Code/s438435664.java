import java.util.*;

public class Main {
    // 最小公倍数
    static long gcd(long x, long y) {
        long tmp = 0;
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }
        while (y > 0) {
            long r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    // 最大公倍数
    static long lcm(long x, long y) {
        return x / gcd(x, y) * y;
    }

    // 階乗
    static long kaijo(long k) {
        long sum = 1;
        for (long i = 1; i <= k; ++i) {
            sum *= i;
            sum %= 1000000000 + 7;
        }
        return sum;
    }

    // for(int i = ; i < ; i++){}

    static long lmax(long s, long t) {
        if (s > t) {
            return s;
        } else {
            return t;
        }
    }

    static long lmin(long s, long t) {
        if (s < t) {
            return s;
        } else {
            return t;
        }
    }

    // ここから開始
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long sum = 0;
        for (int b = 1; b <= n; b++) {
            int cnt = (n + 1) / b;
            int md = (n + 1) % b;
            sum += cnt * Math.max((b - k), 0) + Math.max((md - k), 0);
            if (k == 0) sum--;
        }
        System.out.println(sum);
    }
}
