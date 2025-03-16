import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int INF = (int) Math.pow(10, 11); // Define a large constant for infinity
        int A = Integer.parseInt(br.readLine()); // Read the number of temples
        int B = Integer.parseInt(br.readLine()); // Read the number of shrines
        int Q = Integer.parseInt(br.readLine()); // Read the number of queries
        long[] s = new long[A + 2]; // Create an array for temples with extra space for boundaries
        s[0] = -INF; s[A + 1] = INF; // Set boundary values
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= A; i++) {
            s[i] = Long.parseLong(st.nextToken()); // Read temple locations
        }

        long[] t = new long[B + 2]; // Create an array for shrines with extra space for boundaries
        t[0] = -INF; t[B + 1] = INF; // Set boundary values
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= B; i++) {
            t[i] = Long.parseLong(st.nextToken()); // Read shrine locations
        }

        for (int i = 0; i < Q; i++) {
            long x = Long.parseLong(br.readLine()); // Read the query point
            int b = binarySearch(s, x); // Find closest temples
            int d = binarySearch(t, x); // Find closest shrines
            long res = INF; // Initialize result with infinity
            for (long S : new long[]{s[b - 1], s[b]}) { // Check previous and current temple
                for (long T : new long[]{t[d - 1], t[d]}) { // Check previous and current shrine
                    long d1 = Math.abs(S - x) + Math.abs(T - S); // Calculate distances
                    long d2 = Math.abs(T - x) + Math.abs(S - T); // Calculate distances
                    res = Math.min(res, Math.min(d1, d2)); // Update result with minimum distance
                }
            }

            System.out.println(res); // Print the minimum distance for the query
        }
    }

    // Binary search to find the closest temple or shrine
    private static int binarySearch(long[] arr, long target) {
        int left = 0, right = arr.length - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
