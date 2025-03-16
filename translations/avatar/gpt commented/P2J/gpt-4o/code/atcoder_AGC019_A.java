import java.util.*;
import java.io.*;

public class DrinkCostCalculator {
    // Constants for infinity and modulo
    static final long INF = Long.MAX_VALUE;
    static final long MOD = 1000000007;

    // Function to compute the greatest common divisor
    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to compute the least common multiple
    static long lcm(long x, long y) {
        return (x * y) / gcd(x, y);
    }

    // Function to read an integer from input
    static int readInt() throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    // Function to read a list of integers from input
    static int[] readIntArray() throws IOException {
        String[] tokens = br.readLine().trim().split(" ");
        int[] arr = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            arr[i] = Integer.parseInt(tokens[i]);
        }
        return arr;
    }

    // BufferedReader for fast input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        // Read input values for costs of different types of drinks
        int[] costs = readIntArray();
        int q = costs[0], h = costs[1], s = costs[2], d = costs[3];

        // Read the number of drinks to be purchased
        int n = readInt();

        // Calculate the best price for 1 liter of drink
        long best1L = Math.min(q * 4, Math.min(h * 2, s));

        // Calculate the best price for 2 liters of drink
        long best2L = Math.min(d, best1L * 2);

        // Calculate and print the total cost based on whether n is even or odd
        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2));  // Total cost for even number of drinks
        } else {
            System.out.println(best2L * (n / 2) + best1L);  // Total cost for odd number of drinks
        }
    }
}
<END-OF-CODE>
