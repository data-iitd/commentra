import java.util.Scanner;

public class Main {
    // Macro definitions for convenience
    private static final long MOD = 1000000007; // Definition of modulus for large number calculations

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n; // Variable to store the number of characters
        n = scanner.nextInt(); // Input the number of characters

        // Initialize an array to count occurrences of each character (a-z)
        long[] cnt = new long[26]; // Start with 0 to count occurrences
        char[] s = new char[n]; // Array to store the input characters

        // Read characters and count their occurrences
        for (int i = 0; i < n; i++) {
            s[i] = scanner.next().charAt(0); // Input each character
            cnt[s[i] - 'a']++; // Increment the count for the corresponding character
        }

        long ans = cnt[0]; // Initialize answer with the count of 'a'

        // Calculate the product of counts for all characters from 'b' to 'z'
        for (int i = 1; i < 26; i++) {
            ans = (ans * cnt[i]) % MOD; // Multiply the current answer by the count of the character and take modulo
        }

        // Output the final result, subtracting 1 to exclude the empty product case
        System.out.println(ans - 1);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
