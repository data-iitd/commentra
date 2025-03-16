
import java.util.*;

public class Main {

    public static void main(String[] args) {

        // Read the input tokens and assign them to the variables H, W, A, and B.
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Call the'solve' function with the given input.
        solve(H, W, A, B);
    }

    public static void solve(int H, int W, int A, int B) {

        // Initialize a 2D list named 'answer' of size H x W with all elements set to the string "0".
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
}

