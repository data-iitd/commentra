import java.util.Scanner;

// Block represents a contiguous segment of characters with a specific value and length.
class Block {
    String value; // The character value of the block
    int len;      // The length of the block

    Block(String value, int len) {
        this.value = value;
        this.len = len;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values for N (length of the string) and K (maximum number of '0's allowed)
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Read the input string S
        String S = scanner.nextLine();

        // Generate run-length encoded blocks from the input string S
        Block[] blocks = runLength(S);

        // Initialize variables for the sliding window approach
        int sum = 0, zero = 0, l = 0, ans = 0;

        // Iterate through the blocks to find the maximum length of segments with at most K '0's
        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].len; // Add the length of the current block to the sum

            // Count the number of '0' blocks encountered
            if (blocks[r].value.equals("0")) {
                zero++;
            }

            // If the count of '0' blocks exceeds K, shrink the window from the left
            while (zero > K) {
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

    // RunLength performs run-length encoding on the input string s and returns an array of Block
    public static Block[] runLength(String s) {
        if (s.length() == 0) {
            return new Block[0]; // Return empty array if input string is empty
        }

        // Initialize a list to hold the resulting blocks
        java.util.List<Block> r = new java.util.ArrayList<>();
        char currentChar = s.charAt(0);
        int currentLen = 1;

        for (int i = 1; i < s.length(); i++) {
            char v = s.charAt(i);
            // If the current character matches the block's value, increase the length
            if (currentChar == v) {
                currentLen++;
            } else {
                // Otherwise, append the current block to the result and start a new block
                r.add(new Block(String.valueOf(currentChar), currentLen));
                currentChar = v;
                currentLen = 1;
            }
        }
        // Append the last block to the result
        r.add(new Block(String.valueOf(currentChar), currentLen));

        // Convert the list to an array and return it
        return r.toArray(new Block[0]);
    }
}

// Max returns the maximum of two integers
// This function is not needed in Java as we can use Math.max directly
// <END-OF-CODE>
