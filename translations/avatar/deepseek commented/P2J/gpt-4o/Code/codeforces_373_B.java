import java.util.Scanner;

public class Main {
    // Function to calculate the sum of digits from 1 to k
    public static long sum(long k) {
        long ret = 0;
        long pw = 10;
        long len = 1;

        // Loop to calculate the sum of digits from 1 to k
        while (true) {
            long cur = Math.min(pw - 1, k);
            long prev = pw / 10;

            // Add the count of numbers in the current range to the result
            ret += (cur - prev + 1) * len;

            // Break the loop if the current range exceeds k
            if (pw - 1 >= k) {
                break;
            }

            // Update the length and power of ten for the next range
            len++;
            pw *= 10;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values for w, m, and k
        long w = scanner.nextLong();
        long m = scanner.nextLong();
        long k = scanner.nextLong();

        // Initialize the binary search range
        long lo = 0;
        long hi = (long) 1e18;

        // Perform binary search to find the maximum md
        while (hi - lo > 1) {
            long md = (lo + hi) / 2;

            // Calculate the count of numbers in the range [m, m+md-1]
            long c = sum(m + md - 1) - sum(m - 1);

            // Adjust the search range based on the condition
            if (c * k <= w) {
                lo = md;
            } else {
                hi = md;
            }
        }

        // Print the result of the binary search
        System.out.println(lo);
        
        scanner.close();
    }
}

// <END-OF-CODE>
