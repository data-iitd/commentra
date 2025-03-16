import java.util.Scanner;

public class Main {
    // Recursively calculates the greatest common divisor (GCD) of a and b
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Computes prefix and suffix GCD arrays
    public static int[] ruiseki_lr(int[] array) {
        // Length of the input array
        int n = array.length;
        // Initialize prefix and suffix GCD arrays
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        // Initial GCD value
        int e = 0;
        // Compute prefix GCD array
        for (int i = 0; i < n; i++) {
            left[i + 1] = gcd(left[i], array[i]);
        }
        // Compute suffix GCD array
        for (int i = n - 1; i >= 0; i--) {
            right[i] = gcd(right[i + 1], array[i]);
        }
        return right;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements
        int n = scanner.nextInt();
        // Read the list of elements
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        // Compute prefix and suffix GCD arrays
        int[] right = ruiseki_lr(a);
        // Initialize the answer variable
        int ans = 0;
        // Iterate through the array to find the maximum GCD
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(a[i], right[i + 1]), ans);
        }
        // Print the result
        System.out.println(ans);
    }
}
