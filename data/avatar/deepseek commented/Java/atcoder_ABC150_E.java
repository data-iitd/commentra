import java.io.BufferedReader; // Importing BufferedReader for reading input
import java.io.InputStreamReader; // Importing InputStreamReader for reading input
import java.util.Arrays; // Importing Arrays for sorting

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Creating BufferedReader object to read input
        String[] sa = br.readLine().split(" "); // Reading the first line and splitting it by spaces
        int n = Integer.parseInt(sa[0]); // Parsing the first element as integer n
        sa = br.readLine().split(" "); // Reading the second line and splitting it by spaces
        int[] c = new int[n]; // Initializing an array of size n to store the integers
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(sa[i]); // Parsing each element and storing it in the array c
        }
        br.close(); // Closing the BufferedReader

        int mod = 1000000007; // Defining the modulo value
        if (n == 1) {
            System.out.println(c[0] * 2 % mod); // If n is 1, print the result directly
            return; // Exit the program as no further computation is needed
        }
        Arrays.parallelSort(c); // Sorting the array c in ascending order

        long b = power(2, n); // Calculating 2^n
        long a = power(2, n - 2); // Calculating 2^(n-2)
        long ans = 0; // Initializing the answer variable

        // Calculating the final answer
        for (int i = 2; i <= n + 1; i++) {
            long val = a * i % mod; // Intermediate calculation
            val *= c[n + 1 - i]; // Intermediate calculation
            val %= mod; // Modulo operation
            ans += val; // Adding to the answer
            ans %= mod; // Modulo operation
        }
        ans *= b; // Multiplying the answer by b
        ans %= mod; // Modulo operation
        System.out.println(ans); // Printing the final result
    }

    // Function to calculate x^n % mod
    static long power(long x, long n) {
        if (n == 0) {
            return 1; // Base case: x^0 is 1
        }
        int mod = 1000000007; // Defining the modulo value
        long val = power(x, n / 2); // Recursive call to calculate x^(n/2)
        val = val * val % mod; // Squaring the result
        if (n % 2 == 1) {
            val = val * x % mod; // Multiplying by x if n is odd
        }
        return val; // Returning the result
    }
}
