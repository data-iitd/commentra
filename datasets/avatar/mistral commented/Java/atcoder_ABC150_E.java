import java.io.BufferedReader;  // Importing BufferedReader for reading input from System.in
import java.io.InputStreamReader; // Importing InputStreamReader for wrapping the input stream
import java.util.Arrays;         // Importing Arrays for sorting the array in parallel

public class Main {
    // Main method to start the execution of the program
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Creating a BufferedReader object for reading input
        String[] sa = br.readLine().split(" "); // Reading the first line of input and splitting it into an array of strings
        int n = Integer.parseInt(sa[0]); // Parsing the first element of the array as an integer representing the size of the array
        sa = br.readLine().split(" "); // Reading the second line of input and splitting it into an array of strings
        int[] c = new int[n]; // Creating an integer array of size n

        // Initializing the array c with the input values
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(sa[i]);
        }

        // Closing the BufferedReader to free up resources
        br.close();

        int mod = 1000000007; // Defining a constant value for modulus

        // Checking if the size of the array is 1
        if (n == 1) {
            // Printing the result for the case when the size of the array is 1
            System.out.println(c[0] * 2 % mod);
            return; // Exiting the method after printing the result
        }

        // Sorting the array c in parallel using Arrays.parallelSort() method
        Arrays.parallelSort(c);

        // Calculating the values of b and a
        long b = power(2, n);
        long a = power(2, n - 2);

        // Initializing the variable ans to 0
        long ans = 0;

        // Iterating through the array from index 2 to n+1
        for (int i = 2; i <= n + 1; i++) {
            // Calculating the value of val using the current index i and the previously calculated value a
            long val = a * i % mod;

            // Multiplying the value of val with the current element of the array c[n+1-i]
            val *= c[n + 1 - i];

            // Taking the modulus of the product to ensure the result is within the range of modulus
            val %= mod;

            // Adding the value of val to the variable ans
            ans += val;

            // Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
            ans %= mod;
        }

        // Multiplying the value of ans with the value of b
        ans *= b;

        // Taking the modulus of the product to ensure the result is within the range of modulus
        ans %= mod;

        // Printing the final result
        System.out.println(ans);
    }

    // Static method to calculate the power of a number x raised to the power n
    static long power(long x, long n) {
        if (n == 0) { // Base case when n is 0
            return 1;
        }

        int mod = 1000000007; // Defining a constant value for modulus
        long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

        // If n is odd, multiplying the result with x
        if (n % 2 == 1) {
            val = val * x % mod;
        }

        // Returning the final result
        return val;
    }
}
