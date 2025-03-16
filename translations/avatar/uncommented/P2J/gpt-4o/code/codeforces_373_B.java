import java.util.Scanner;

public class Main {
    public static long sum(long k) {
        long ret = 0;
        long pw = 10;
        long len = 1;
        while (true) {
            long cur = Math.min(pw - 1, k);
            long prev = pw / 10;
            ret += (cur - prev + 1) * len;
            if (pw - 1 >= k) {
                break;
            }
            len++;
            pw *= 10;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long w = scanner.nextLong();
        long m = scanner.nextLong();
        long k = scanner.nextLong();
        long lo = 0;
        long hi = (long) 1e18;

        while (hi - lo > 1) {
            long md = (lo + hi) / 2;
            long c = sum(m + md - 1) - sum(m - 1);
            if (c * k <= w) {
                lo = md;
            } else {
                hi = md;
            }
        }
        System.out.println(lo);
        scanner.close();
    }
}
// <END-OF-CODE>
