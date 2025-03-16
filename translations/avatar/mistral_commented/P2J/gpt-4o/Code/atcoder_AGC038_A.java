import java.util.Scanner;

public class Main {

    // Define a method named 'solve' that takes four integer arguments: H, W, A, and B.
    public static void solve(int H, int W, int A, int B) {
        // Initialize a 2D array named 'answer' of size H x W with all elements set to the string "0".
        String[][] answer = new String[H][W];
        for (int i = 0; i < H; i++) {
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
            System.out.println(String.join("", answer[i]));
        }
    }

    // Define the main method.
    public static void main(String[] args) {
        // Create a Scanner object for reading input.
        Scanner scanner = new Scanner(System.in);

        // Read the input values and assign them to the variables H, W, A, and B.
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Call the 'solve' method with the given input.
        solve(H, W, A, B);

        // Close the scanner.
        scanner.close();
    }
}

// <END-OF-CODE>
