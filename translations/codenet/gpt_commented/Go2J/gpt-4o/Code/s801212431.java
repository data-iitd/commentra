import java.util.Scanner;

public class Main {
    // Function to return the minimum of two integers
    public static int min(int x, int y) {
        return (x > y) ? y : x; // Return y if x is greater, otherwise return x
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner to read from standard input
        String S = sc.next(); // Read the input string

        int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
        // Loop through each character in the input string
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '0') {
                l0++; // Increment the counter for '0'
            } else {
                l1++; // Increment the counter for '1'
            }
        }
        // Print the result, which is twice the minimum count of '0's or '1's
        System.out.println(2 * min(l0, l1));
        sc.close(); // Close the scanner
    }
}
// <END-OF-CODE>
