
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt(); // Read the number of temples
        int B = sc.nextInt(); // Read the number of shrines
        int Q = sc.nextInt(); // Read the number of queries
        int[] s = new int[A+2]; // Create a slice for temples with extra space for boundaries
        s[0] = -1000000000; s[A+1] = 1000000000; // Set boundary values
        for (int i = 1; i <= A; i++) {
            s[i] = sc.nextInt(); // Read temple locations
        }

        int[] t = new int[B+2]; // Create a slice for shrines with extra space for boundaries
        t[0] = -1000000000; t[B+1] = 1000000000; // Set boundary values
        for (int i = 1; i <= B; i++) {
            t[i] = sc.nextInt(); // Read shrine locations
        }

        for (int i = 0; i < Q; i++) {
            int x = sc.nextInt(); // Read the query point
            int b = findClosest(s, x); // Find closest temple
            int d = findClosest(t, x); // Find closest shrine
            int res = 1000000000; // Initialize result with infinity
            for (int S : new int[] {s[b-1], s[b]}) { // Check previous and current temple
                for (int T : new int[] {t[d-1], t[d]}) { // Check previous and current shrine
                    int d1 = Math.abs(S-x) + Math.abs(T-S); // Calculate distances
                    int d2 = Math.abs(T-x) + Math.abs(S-T);
                    res = Math.min(res, Math.min(d1, d2)); // Update result with minimum distance
                }
            }

            System.out.println(res); // Print the minimum distance for the query
        }
    }

    public static int findClosest(int[] s, int x) {
        int lo = 0;
        int hi = s.length-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (s[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
}

