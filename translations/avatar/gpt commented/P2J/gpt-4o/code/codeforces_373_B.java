import java.util.Scanner;

public class Main {
    // Function to calculate the sum of digits up to k
    public static long sum(long k) {
        // Initialize the result variable to store the total count
        long ret = 0;
        // Initialize the power of ten to track the current range
        long pw = 10;
        // Initialize the length of the current digit
        long length = 1;

        // Loop indefinitely until a break condition is met
        while (true) {
            // Calculate the current upper limit for the range
            long cur = Math.min(pw - 1, k);
            // Calculate the previous lower limit for the range
            long prev = pw / 10;

            // Update the result with the count of numbers in the current range
            ret += (cur - prev + 1) * length;

            // If the current upper limit exceeds k, exit the loop
            if (pw - 1 >= k) {
                break;
            }

            // Increase the length for the next range of digits
            length++;
            // Move to the next power of ten
            pw *= 10;
        }

        // Return the total count of numbers up to k
        return ret;
    }

    public static void main(String[] args) {
        // Read input values for w, m, and k
        Scanner scanner = new Scanner(System.in);
        long w = scanner.nextLong();
        long m = scanner.nextLong();
        long k = scanner.nextLong();
        scanner.close();

        // Initialize the lower and upper bounds for binary search
        long lo = 0;
        long hi = (long) 1e18;

        // Perform binary search to find the maximum value satisfying the condition
        while (hi - lo > 1) {
            // Calculate the midpoint of the current bounds
            long md = (lo + hi) / 2;

            // Calculate the count of numbers in the range [m, m + md - 1]
            long c = sum(m + md - 1) - sum(m - 1);

            // Check if the count multiplied by k is less than or equal to w
            if (c * k <= w) {
                // If true, adjust the lower bound to md
                lo = md;
            } else {
                // Otherwise, adjust the upper bound to md
                hi = md;
            }
        }

        // Print the final result which is the maximum value found
        System.out.println(lo);
    }
}

// <END-OF-CODE>
