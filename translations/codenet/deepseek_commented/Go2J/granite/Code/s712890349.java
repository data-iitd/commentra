

import java.util.Scanner;

public class s712890349{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();

        // Apply Run Length Encoding to the input string S
        String[] blocks = RunLength(S);

        // Initialize variables for the sliding window approach
        int sum = 0, zero = 0, l = 0;
        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].length(); // Add the length of the current block to the sum
            if (blocks[r].equals("0")) {
                zero++; // Increment the count of '0' blocks
            }
            // Adjust the window size if the number of '0' blocks exceeds K
            while (K < zero) {
                sum -= blocks[l].length(); // Subtract the length of the block at the left of the window
                if (blocks[l].equals("0")) {
                    zero--; // Decrement the count of '0' blocks
                }
                l++; // Move the left pointer to the right
            }
            ans = Math.max(ans, sum); // Update the answer if the current window sum is greater
        }
        System.out.println(ans); // Print the final answer
    }

    // RunLength performs run-length encoding on the input string
    public static String[] RunLength(String s) {
        if (s.length() == 0) {
            return new String[0]; // Return an empty array if the input string is empty
        }
        String t = s.substring(0, 1); // Initialize the first block
        int len = 1;
        String[] r = new String[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(0)) {
                len++; // Increment the length of the current block if the character is the same
            } else {
                r[i - 1] = t + len; // Append the current block to the result array
                t = s.substring(i, i + 1); // Initialize a new block for the new character
                len = 1;
            }
        }
        r[s.length() - 1] = t + len; // Append the last block to the result array
        return r;
    }
}

// Translate the above Java code to Python and end with comment "