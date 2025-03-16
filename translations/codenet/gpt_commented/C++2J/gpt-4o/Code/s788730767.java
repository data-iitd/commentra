import java.util.Scanner;

public class Main {
    // Global variables
    static int n, p, b = 0, c = 0;
    static int[] a = new int[50];

    // Function to calculate permutations nPr
    static long nPr(long n, long r) {
        long res = 1;
        // Calculate nPr using the formula n! / (n - r)!
        for (int i = 0; i < r; i++) {
            res *= (n - i); // Multiply by (n - i) for r times
        }
        return res; // Return the result
    }

    // Function to calculate combinations nCr
    static long nCr(long n, long r) {
        // Using the formula nCr = nPr(n, r) / r!
        double res = 1;
        // Calculate nCr using an iterative approach to avoid large intermediate values
        for (int i = 0; i < r; i++) {
            res *= (n - i); // Multiply by (n - i)
            res /= (i + 1); // Divide by (i + 1) to account for r!
        }
        return (long) res; // Return the result as long
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of elements and the parity flag
        n = scanner.nextInt();
        p = scanner.nextInt();

        // Read the array elements and count even and odd numbers
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Input each element
            if (a[i] % 2 == 0) {
                b++; // Increment even count
            } else {
                c++; // Increment odd count
            }
        }

        // Initialize sums for combinations
        long bsum = 0, csum = 0;
        // Calculate the total subsets of even numbers (2^b)
        bsum = (long) Math.pow(2, b);

        // Calculate combinations of odd numbers based on the parity flag
        if (p == 0) {
            // If p is 0, count combinations of even counts of odd numbers
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 0) {
                    csum += nCr(c, i); // Add combinations for even i
                }
            }
        } else {
            // If p is 1, count combinations of odd counts of odd numbers
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 1) {
                    csum += nCr(c, i); // Add combinations for odd i
                }
            }
        }

        // Calculate the final answer as the product of bsum and csum
        long ans = bsum * csum;
        // Output the result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
