public class PrimePairs {
    static int[] flag; // Declare a static integer array to keep track of prime numbers

    // Method to mark non-prime numbers up to a given number 'num'
    public static void prime(int num) {
        flag = new int[num + 1]; // Allocate memory for the flag array
        for (int i = 2; i * i <= num; i++) { // Iterate to mark non-prime numbers
            if (flag[i] == 0) { // If 'i' is a prime number
                for (int j = 2; i * j <= num; j++) { // Mark multiples of 'i' as non-prime
                    flag[i * j] = 1;
                }
            }
        }
    }

    // Main method to read an integer, calculate pairs of primes summing to 'n', and print the result
    public static void main(String[] args) {
        prime(50000); // Call the prime method to mark non-prime numbers up to 50000
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a scanner object to read input

        while (true) { // Infinite loop to read input until 'n' is zero
            int n = scanner.nextInt(); // Read an integer 'n' from the user
            if (n == 0) {
                break; // Exit the loop if 'n' is zero
            }
            int i = 2; // Initialize the starting prime number
            int cnt = 0; // Initialize the count of pairs
            while (i * 2 <= n) { // Loop to find pairs of primes summing to 'n'
                if (flag[i] == 0 && flag[n - i] == 0) { // Check if both 'i' and 'n-i' are prime
                    cnt++; // Increment the count if a valid pair is found
                }
                i++; // Move to the next potential prime number
            }
            System.out.println(cnt); // Print the count of pairs of primes summing to 'n'
        }

        scanner.close(); // Close the scanner object
    }
}
