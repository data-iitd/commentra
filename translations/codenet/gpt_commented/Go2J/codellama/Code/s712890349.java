
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Read input values for N (length of the string) and K (maximum number of '0's allowed)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Read the input string S
        String S = sc.next();

        // Generate run-length encoded blocks from the input string S
        Block[] blocks = RunLength(S);

        // Initialize variables for the sliding window approach
        int sum = 0, zero = 0, l = 0;

        // Iterate through the blocks to find the maximum length of segments with at most K '0's
        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].len; // Add the length of the current block to the sum

            // Count the number of '0' blocks encountered
            if (blocks[r].value.equals("0")) {
                zero++;
            }

            // If the count of '0' blocks exceeds K, shrink the window from the left
            while (K < zero) {
                sum -= blocks[l].len; // Subtract the length of the leftmost block from the sum
                if (blocks[l].value.equals("0")) {
                    zero--; // Decrease the count of '0' blocks
                }
                l++; // Move the left pointer to the right
            }

            // Update the answer with the maximum sum found so far
            ans = Math.max(ans, sum);
        }

        // Print the maximum length of segments with at most K '0's
        System.out.println(ans);
    }

    // RunLength performs run-length encoding on the input string s and returns a slice of Block
    public static Block[] RunLength(String s) {
        Block[] r = new Block[s.length()]; // Slice to hold the resulting blocks
        if (s.length() == 0) {
            return r; // Return empty slice if input string is empty
        }

        // Initialize the first block with the first character of the string
        Block t = new Block(s.charAt(0), 1);
        for (int i = 1; i < s.length(); i++) {
            // If the current character matches the block's value, increase the length
            if (t.value.equals(String.valueOf(s.charAt(i)))) {
                t.len++;
            } else {
                // Otherwise, append the current block to the result and start a new block
                r[i - 1] = t;
                t = new Block(s.charAt(i), 1);
            }
        }
        // Append the last block to the result
        r[s.length() - 1] = t;
        return r; // Return the slice of blocks
    }

    // Max returns the maximum of two integers
    public static int Max(int a, int b) {
        if (b > a) {
            return b; // Return b if it is greater than a
        }
        return a; // Otherwise, return a
    }

    // Block represents a contiguous segment of characters with a specific value and length.
    public static class Block {
        public String value; // The character value of the block
        public int len; // The length of the block

        public Block(char value, int len) {
            this.value = String.valueOf(value);
            this.len = len;
        }
    }
}

