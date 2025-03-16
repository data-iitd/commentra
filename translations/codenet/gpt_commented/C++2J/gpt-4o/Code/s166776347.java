import java.util.Scanner;

public class Main {
    // Define constants
    static final long MOD = 1000000007; // Define a modulus value for calculations

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input: Read the values of N and K
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[(int) N]; // Create an array of size N
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong(); // Read N elements into array A
        }

        // Solution: Calculate the number of inversions in the array
        long ans1 = 0; // Initialize the count of inversions
        for (int i = 0; i < N; i++) { // Iterate through each element
            for (int j = 0; j < N; j++) { // Compare with every other element
                if (i >= j) continue; // Skip if i is greater than or equal to j
                if (A[i] > A[j]) ans1++; // Count inversion if A[i] > A[j]
                ans1 %= MOD; // Take modulo to prevent overflow
            }
        }

        // Count occurrences of each element in the array
        long[] count = new long[2005]; // Initialize a count array to store frequencies
        for (int i = 0; i < N; i++) { // Iterate through the array
            count[(int) (A[i] - 1)]++; // Increment the count for the corresponding value
        }

        // Calculate the second part of the answer based on the counts
        long ans2 = 0; // Initialize the second answer
        long remain = N; // Remaining elements to consider
        for (int i = 0; i < 2005; i++) { // Iterate through the count array
            remain -= count[i]; // Decrease the remaining count by the current count
            ans2 += count[i] * remain; // Calculate pairs of inversions
        }

        // Calculate the final answer based on ans1 and ans2
        long ans = 0; // Initialize the final answer
        long tmp = K * (K - 1); // Calculate the number of ways to choose 2 from K
        tmp /= 2; // Divide by 2 to get combinations
        tmp %= MOD; // Take modulo
        tmp *= ans2; // Multiply by the second answer
        tmp %= MOD; // Take modulo again
        ans += ans1 * K; // Add the contribution from ans1
        ans %= MOD; // Take modulo
        ans += tmp; // Add the contribution from tmp
        ans %= MOD; // Take modulo

        // Output: Print the final answer
        System.out.println(ans); // Output the result
    }
}
// <END-OF-CODE>
