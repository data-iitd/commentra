import java.util.*;
import java.io.*;

public class Main {
    // Constants
    static final long INF = Long.MAX_VALUE;
    static final long MOD = 1000000007;

    // Helper functions
    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long lcm(long x, long y) {
        return (x * y) / gcd(x, y);
    }

    static long lcmList(long[] nums) {
        long result = 1;
        for (long num : nums) {
            result = lcm(result, num);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // Read input
        long q = Long.parseLong(st.nextToken());
        long h = Long.parseLong(st.nextToken());
        long s = Long.parseLong(st.nextToken());
        long d = Long.parseLong(st.nextToken());
        long n = Long.parseLong(br.readLine());

        // Calculate the length of the longest segment that can be formed
        long best1L = Math.min(q * 4, Math.min(h * 2, s));
        long best2L = Math.min(d, best1L * 2);

        // Check if n is even
        if (n % 2 == 0) {
            // If it is, print the length of the longest segment that can be formed
            System.out.println(best2L * (n / 2));
        } else {
            // If n is odd, print the length of the longest segment that can be formed
            System.out.println(best2L * (n / 2) + best1L);
        }
    }
}
// <END-OF-CODE>
