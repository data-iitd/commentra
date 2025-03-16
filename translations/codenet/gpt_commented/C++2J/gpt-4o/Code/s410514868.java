import java.util.Scanner;

public class Main {
    // Define long long type for large integers
    static long n, k, ans = 0, L, ans2 = 0;
    static String s;

    public static void main(String[] args) {
        // Create a scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of characters (n) and the maximum number of operations (k)
        n = scanner.nextLong();
        k = scanner.nextLong();
        
        // Read the string of characters
        s = scanner.next();
        
        // Initialize L with the first character of the string
        L = s.charAt(0);
        long cnt = 0; // Initialize a counter for consecutive characters

        // Iterate through the string starting from the second character
        for (int i = 1; i < n; i++) {
            // If the current character is the same as the last character
            if (L == s.charAt(i)) {
                cnt++; // Increment the counter
            } else {
                // If the character changes, update L and add the count to ans
                L = s.charAt(i);
                ans += cnt; // Add the count of consecutive characters to ans
                ans2++; // Increment the number of distinct character groups
                cnt = 0; // Reset the counter for the new character
            }
        }

        // After the loop, add the count of the last group of characters to ans
        ans += cnt;
        ans2++; // Increment for the last group

        // Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
        System.out.println(ans + Math.min(2 * k, ans2 - 1));

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
