
// Importing required packages
import java.util.*;

// s712890349 class
public class s712890349{
    // s712890349 function starts the execution
    public static void main(String[] args) {
        // Initialize variables
        int N, K, ans = 0;

        // Read input values for N and K from the standard input
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        // Read the input string S from the standard input
        String S = sc.next();

        // Call the RunLength function to get the run-length encoded blocks
        List<Block> blocks = RunLength(S);

        // Initialize variables sum, zero and length l
        int sum = 0, zero = 0, l = 0;

        // Loop through all the blocks in the blocks list
        for (int r = 0; r < blocks.size(); r++) {
            // Increment the sum by the length of the current block
            sum += blocks.get(r).Len;

            // If the current block's value is '0', increment the zero counter
            if (blocks.get(r).Value.equals("0")) {
                zero++;
            }

            // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
            while (K < zero) {
                sum -= blocks.get(l).Len;
                if (blocks.get(l).Value.equals("0")) {
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
    public static List<Block> RunLength(String s) {
        // If the length of the input string is zero, return an empty list
        if (s.length() == 0) {
            return new ArrayList<>();
        }

        // Initialize the first block with the first character and length one
        Block t = new Block(String.valueOf(s.charAt(0)), 1);

        // Initialize an empty list to store the blocks
        List<Block> r = new ArrayList<>();

        // Loop through all the characters in the input string starting from the second character
        for (int i = 1; i < s.length(); i++) {
            // If the current character is the same as the previous character, increment the length of the current block
            if (t.Value.equals(String.valueOf(s.charAt(i)))) {
                t.Len++;
            } else {
                // Add the previous block to the result list
                r.add(t);

                // Initialize a new block with the current character and length one
                t = new Block(String.valueOf(s.charAt(i)), 1);
            }
        }

        // Add the last block to the result list
        r.add(t);

        // Return the result list
        return r;
    }

    // Block class to represent a block in the run-length encoding
    public static class Block {
        String Value;
        int Len;

        public Block(String value, int len) {
            Value = value;
            Len = len;
        }
    }
}

// End of the code