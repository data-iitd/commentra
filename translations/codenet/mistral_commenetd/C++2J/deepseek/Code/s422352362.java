import java.util.*;
import java.io.*;

public class Main {
    // Define the size of the array
    static final int MAX_N = 200005;

    // Initialize arrays
    static long[] a = new long[MAX_N];
    static long[] pre = new long[MAX_N];
    static long[] last = new long[MAX_N];

    public static void main(String[] args) throws IOException {
        // Read the number of elements in the array
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        // Read the elements of the array
        String[] input = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(input[i - 1]);
            // Initialize pre and last arrays
            pre[i] = pre[i - 1] + a[i];
            last[i] = last[i + 1] + a[i];
        }

        // Initialize sum of prefix and suffix arrays to zero
        long sumpre = 0, sumlast = 0;

        // Calculate prefix sum
        for (int i = 1; i < n; i++) {
            sumpre += a[i];
            pre[i] = sumpre;
        }

        // Calculate suffix sum
        for (int i = n; i > 0; i--) {
            sumlast += a[i];
            last[i] = sumlast;
        }

        // Initialize difference as maximum long long value
        long d = Long.MAX_VALUE;

        // Find the minimum difference between prefix and suffix sums
        for (int i = 1; i < n; i++) {
            d = Math.min(d, Math.abs(pre[i] - last[i + 1]));
        }

        // Print the minimum difference
        System.out.println(d);
    }
}
