import java.util.Scanner;

public class Main {
    // Define a constant for the maximum size of the strings
    static final int M = 1010;

    public static void main(String[] args) {
        // Declare character arrays to hold the input strings
        char[] a = new char[M];
        char[] b = new char[M];

        // Declare variables for the lengths of the strings and the minimum answer
        int n, m, ans = M + 10;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the first string into array 'a'
        String inputA = scanner.next();
        n = inputA.length();
        for (int i = 0; i < n; i++) {
            a[i + 1] = inputA.charAt(i);
        }

        // Read the second string into array 'b'
        String inputB = scanner.next();
        m = inputB.length();
        for (int i = 0; i < m; i++) {
            b[i + 1] = inputB.charAt(i);
        }

        // Iterate over all possible starting positions in 'a' where 'b' can fit
        for (int i = 1; i + m - 1 <= n; i++) {
            // Initialize a variable to count the number of mismatches
            int sum = 0;

            // Compare the substring of 'a' with 'b' character by character
            for (int j = 1; j <= m; j++) {
                // Increment the mismatch count if characters do not match
                if (a[i + j - 1] != b[j]) {
                    sum++;
                }
            }

            // Update the minimum number of mismatches found
            ans = Math.min(ans, sum);
        }

        // Output the minimum number of mismatches
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
