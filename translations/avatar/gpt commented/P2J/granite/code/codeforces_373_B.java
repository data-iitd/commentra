
import java.util.*;

public class codeforces_373_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long w = sc.nextLong();
        long m = sc.nextLong();
        long k = sc.nextLong();
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
    }

    static long sum(long k) {
        long ret = 0;
        long pw = 10;
        long length = 1;
        while (true) {
            long cur = Math.min(pw - 1, k);
            long prev = pw / 10;
            ret += (cur - prev + 1) * length;
            if (pw - 1 >= k) {
                break;
            }
            length += 1;
            pw *= 10;
        }
        return ret;
    }
}

// Read input values for w, m, and k
// Initialize the lower and upper bounds for binary search
// Perform binary search to find the maximum value satisfying the condition
// Print the final result which is the maximum value found
