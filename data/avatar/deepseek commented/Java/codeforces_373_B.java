
import java.io.*;
import java.util.*;

public class Main {
    // Global variable to store the answer
    public static long ans = 0;

    // Helper function to calculate the sum of numbers based on a specific pattern
    public static long get(long a) {
        long ret = 0;
        long now = 1;
        long t = 1;
        for (; ; ) {
            if (now * 10 > a) {
                ret += (a - now + 1) * t;
                break;
            }
            ret += now * 9 * t;
            now *= 10;
            t++;
        }
        return ret;
    }

    // Binary search function to find the desired value
    public static long binarySearch(long k, long l, long r, long x) {
        if (r >= l) {
            long mid = l + (r - l) / 2;
            if (mid > ans && mid * k <= x) ans = mid;

            if (k * mid == x) return mid;

            if (k * mid > x) return binarySearch(k, l, mid - 1, x);

            return binarySearch(k, mid + 1, r, x);
        }

        return -1;
    }

    // Setup for input and output using BufferedReader and PrintWriter
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);

    // Main function where the execution starts
    public static void main(String[] args) throws IOException {
        Scanner S = new Scanner(System.in);
        long gen, st, tim;
        gen = S.nextLong();
        st = S.nextLong();
        tim = S.nextLong();
        gen /= tim;
        long beg = st - 1, end = (long) Math.pow(10, 18);
        while (true) {
            long med = (beg + end) / 2 + 1;
            if (get(med) - get(st - 1) > gen) {
                end = med - 1;
            } else {
                beg = med;
            }
            if (beg == end) {
                System.out.println(beg - st + 1);
                break;
            }
        }
    }
}

