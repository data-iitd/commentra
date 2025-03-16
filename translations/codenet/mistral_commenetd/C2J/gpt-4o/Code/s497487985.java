import java.util.Scanner;

public class Main {
    // Function to find the greatest common divisor (GCD) of two integers
    public static long gcd(long a, long b) {
        if (b == 0) {
            // If 'b' is 0, then 'a' is the GCD
            return a;
        } else {
            // Otherwise, recursively call the function with 'b' and the remainder of 'a' divided by 'b'
            return gcd(b, a % b);
        }
    }

    // Function to find the least common multiple (LCM) of two integers
    public static long lcm(long a, long b) {
        // The LCM is the product of the two numbers divided by their GCD
        return a * b / gcd(a, b);
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n; // Number of people
        long k; // Total points
        long q; // Number of queries
        long[] a = new long[100001]; // Array to store the query numbers
        long[] point = new long[100001]; // Array to store the current points for each person

        // Read input values
        n = scanner.nextLong();
        k = scanner.nextLong();
        q = scanner.nextLong();

        // Check if it's possible to distribute the points to all queries
        if (q < k) {
            // If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
            for (long i = 0; i < n; i++) {
                System.out.println("Yes"); // This will never be reached
                return;
            }
        }

        // Distribute the points to each query one by one
        for (long i = 0; i < q; i++) {
            a[(int) i] = scanner.nextLong(); // Read the query number
            point[(int) (a[(int) i] - 1)]++; // Increase the points for the person with the query number
        }

        // Check if it's possible to distribute the remaining points to the remaining people
        for (long i = 0; i < n; i++) {
            if (k - (q - point[(int) i]) > 0) { // If the remaining points are greater than the difference between the total points and the points already distributed
                System.out.println("Yes"); // It's possible to distribute the remaining points to the remaining people
            } else {
                System.out.println("No"); // It's impossible to distribute the remaining points to the remaining people
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
