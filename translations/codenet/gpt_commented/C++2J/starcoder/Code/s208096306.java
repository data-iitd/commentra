import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = sc.nextInt();
        for (int i = 1; i < n; ++i) {
            int a = sc.nextInt();
            ans = gcd(ans, a);
        }
        System.out.println(ans);
    }

    // Function to compute the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        // Ensure 'a' is the larger number for the algorithm
        if (a < b) swap(a, b);
        int r;
        // Apply the Euclidean algorithm to find the GCD
        while ((r = a % b) > 0) {
            a = b; // Update 'a' to 'b'
            b = r; // Update 'b' to the remainder
        }
        return b; // Return the GCD
    }
}

