// Importing required packages
import java.util.Scanner;

// Define a custom class 'Block'
class Block {
    String value;
    int len;

    // Constructor for Block
    Block(String value, int len) {
        this.value = value;
        this.len = len;
    }
}

// Main class
public class Main {
    // Main function starts the execution
    public static void main(String[] args) {
        // Initialize variables
        int N, K, ans = 0;

        // Read input values for N and K from the standard input
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read the input string S from the standard input
        String S = scanner.nextLine();

        // Call the RunLength function to get the run-length encoded blocks
        Block[] blocks = runLength(S);

        // Initialize variables sum, zero and length l
        int sum = 0, zero = 0, l = 0;

        // Loop through all the blocks in the blocks array
        for (int r = 0; r < blocks.length; r++) {
            // Increment the sum by the length of the current block
            sum += blocks[r].len;

            // If the current block's value is '0', increment the zero counter
            if (blocks[r].value.equals("0")) {
                zero++;
            }

            // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
            while (zero > K) {
                sum -= blocks[l].len;
                if (blocks[l].value.equals("0")) {
                    zero--;
                }
                l++;
            }

            // Update the answer with the maximum of the current answer and the sum
            ans = Math.max(ans, sum);
        }

        // Print the final answer
        System.out.println(ans);
    }

    // RunLength function to get the run-length encoded blocks
    public static Block[] runLength(String s) {
        // If the length of the input string is zero, return an empty array
        if (s.length() == 0) {
            return new Block[0];
        }

        // Initialize the first block with the first character and length one
        Block t = new Block(String.valueOf(s.charAt(0)), 1);

        // Initialize a dynamic list to store the blocks
        java.util.ArrayList<Block> r = new java.util.ArrayList<>();

        // Loop through all the characters in the input string starting from the second character
        for (int i = 1; i < s.length(); i++) {
            char v = s.charAt(i);
            // If the current character is the same as the previous character, increment the length of the current block
            if (t.value.equals(String.valueOf(v))) {
                t.len++;
            } else {
                // Add the previous block to the result list
                r.add(t);
                // Initialize a new block with the current character and length one
                t = new Block(String.valueOf(v), 1);
            }
        }

        // Add the last block to the result list
        r.add(t);

        // Convert the list to an array and return it
        return r.toArray(new Block[0]);
    }
}

// End of the code
// <END-OF-CODE>
