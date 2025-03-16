
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // Read the list of elements
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        // Compute prefix and suffix GCD arrays
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        left[0] = 0;
        right[n] = 0;
        for (int i = 0; i < n; i++) {
            left[i + 1] = gcd(left[i], a[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            right[i] = gcd(right[i + 1], a[i]);
        }
        // Initialize the answer variable
        int ans = 0;
        // Iterate through the array to find the maximum GCD
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }
        // Print the result
        System.out.println(ans);
    }

    // Defines a lambda function to compute GCD
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

