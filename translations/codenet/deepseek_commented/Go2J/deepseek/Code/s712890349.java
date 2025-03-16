import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Block {
    String value;
    int len;

    Block(String value, int len) {
        this.value = value;
        this.len = len;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of characters
        int K = scanner.nextInt(); // Read the maximum allowed changes
        scanner.nextLine(); // Consume the newline
        String S = scanner.nextLine(); // Read the input string

        // Apply Run Length Encoding to the input string S
        List<Block> blocks = runLengthEncoding(S);

        // Initialize variables for the sliding window approach
        int sum = 0, zero = 0, l = 0, ans = 0;
        for (int r = 0; r < blocks.size(); r++) {
            sum += blocks.get(r).len; // Add the length of the current block to the sum
            if (blocks.get(r).value.equals("0")) {
                zero++; // Increment the count of '0' blocks
            }
            // Adjust the window size if the number of '0' blocks exceeds K
            while (K < zero) {
                sum -= blocks.get(l).len; // Subtract the length of the block at the left of the window
                if (blocks.get(l).value.equals("0")) {
                    zero--; // Decrement the count of '0' blocks
                }
                l++; // Move the left pointer to the right
            }
            ans = Math.max(ans, sum); // Update the answer if the current window sum is greater
        }
        System.out.println(ans); // Print the final answer
    }

    // RunLengthEncoding performs run-length encoding on the input string
    public static List<Block> runLengthEncoding(String s) {
        List<Block> r = new ArrayList<>(); // Initialize a list to store the encoded blocks
        if (s.length() == 0) {
            return r; // Return an empty list if the input string is empty
        }
        Block t = new Block(String.valueOf(s.charAt(0)), 1); // Initialize the first block
        for (int i = 1; i < s.length(); i++) {
            if (t.value.equals(String.valueOf(s.charAt(i)))) {
                t.len++; // Increment the length of the current block if the character is the same
            } else {
                r.add(t); // Add the current block to the result list
                t = new Block(String.valueOf(s.charAt(i)), 1); // Initialize a new block for the new character
            }
        }
        r.add(t); // Add the last block to the result list
        return r;
    }
}

