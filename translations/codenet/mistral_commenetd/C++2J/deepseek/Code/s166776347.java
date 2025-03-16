public class Main {
    public static void main(String[] args) {
        // Input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long N = scanner.nextLong(); // Number of elements in array A and the value of K
        long K = scanner.nextLong(); // Number of elements in array A and the value of K
        long[] A = new long[(int) N]; // Array to store input elements
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong(); // Read elements of array A from standard input
        }

        // Solution
        long ans1 = 0; // Initialize answer for the first part
        for (int i = 0; i < N; i++) { // Iterate through all elements in array A
            for (int j = 0; j < N; j++) { // Iterate through all other elements in array A
                if (i >= j) continue; // Skip if current index is greater than or equal to the index of the inner loop
                if (A[i] > A[j]) ans1++; // Increment answer if the current element is greater than the inner element
                ans1 %= 1000000007; // Update answer modulo 1e9+7 to avoid overflow
            }
        }

        long[] count = new long[2005]; // Initialize an array to store the count of each unique element in array A
        for (int i = 0; i < N; i++) { // Iterate through all elements in array A
            count[Math.toIntExact(A[i] - 1)]++; // Increment the count of the current element in the count array
        }

        long ans2 = 0; // Initialize answer for the second part
        long remain = N; // Initialize the remaining number of elements to be paired
        for (int i = 0; i < 2005; i++) { // Iterate through all unique elements in array A
            remain -= count[i]; // Decrement the remaining number of elements to be paired for the current unique element
            ans2 += count[i] * remain; // Calculate the contribution of the current unique element to the answer
        }

        long ans = 0; // Initialize the final answer
        long tmp = K * (K - 1) / 2; // Calculate (K*(K-1)) modulo 1e9+7
        tmp %= 1000000007; // Update the temporary variable modulo 1e9+7
        tmp *= ans2; // Multiply the temporary variable with the answer for the second part
        tmp %= 1000000007; // Update the temporary variable modulo 1e9+7
        ans += ans1 * K; // Add the answer for the first part multiplied by K to the final answer
        ans %= 1000000007; // Update the final answer modulo 1e9+7
        ans += tmp; // Add the temporary variable to the final answer
        ans %= 1000000007; // Update the final answer modulo 1e9+7

        // Output
        System.out.println(ans); // Print the final answer
    }
}
