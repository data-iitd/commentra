
// Import the java.util.Scanner class for reading input from standard input.
import java.util.Scanner;

// Define a class named 'Solution' that implements the 'Runnable' interface.
class Solution implements Runnable {

    // Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
    public void solve(int H, int W, int A, int B) {

        // Initialize a 2D array named 'answer' of size H x W with all elements set to the string "0".
        String[][] answer = new String[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                answer[i][j] = "0";
            }
        }

        // Iterate through each row 'i' in the range of H.
        for (int i = 0; i < H; i++) {
            // Iterate through each column 'j' in the range of W.
            for (int j = 0; j < W; j++) {
                // Set the value of the cell 'answer[i][j]' based on the conditions.
                if (i < B) {
                    if (j < A) {
                        answer[i][j] = "0";
                    } else {
                        answer[i][j] = "1";
                    }
                } else {
                    if (j < A) {
                        answer[i][j] = "1";
                    } else {
                        answer[i][j] = "0";
                    }
                }
            }
        }

        // Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(answer[i][j]);
            }
            System.out.println();
        }
    }

    // Define a function named 'main' that does not take any arguments.
    public static void main(String[] args) {

        // Define an inner class named 'IterateTokens' that reads input from standard input and yields each token as a string.
        class IterateTokens {
            private Scanner scanner = new Scanner(System.in);
            public String next() {
                return scanner.next();
            }
        }

        // Read the input tokens and assign them to the variables H, W, A, and B.
        IterateTokens tokens = new IterateTokens();
        int H = Integer.parseInt(tokens.next());
        int W = Integer.parseInt(tokens.next());
        int A = Integer.parseInt(tokens.next());
        int B = Integer.parseInt(tokens.next());

        // Call the 'solve' function with the given input.
        Solution solution = new Solution();
        solution.solve(H, W, A, B);
    }
}

// End of code.
