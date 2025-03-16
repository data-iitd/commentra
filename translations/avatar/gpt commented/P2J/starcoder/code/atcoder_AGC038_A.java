import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values for H, W, A, and B
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Call the solve function with the input parameters
        solve(H, W, A, B);
    }

    public static void solve(int H, int W, int A, int B) {
        // Initialize a 2D list (matrix) with dimensions H x W filled with "0"
        String[][] answer = new String[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                answer[i][j] = "0";
            }
        }

        // Fill the matrix based on the conditions involving A and B
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // If we are in the first B rows
                if (i < B) {
                    // If we are in the first A columns
                    if (j < A) {
                        answer[i][j] = "0";  // Set to "0"
                    } else {
                        answer[i][j] = "1";  // Set to "1" for columns >= A
                    }
                } else {
                    // If we are in rows >= B
                    if (j < A) {
                        answer[i][j] = "1";  // Set to "1" for columns < A
                    } else {
                        answer[i][j] = "0";  // Set to "0" for columns >= A
            }
        }

        // Print the resulting matrix row by row
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(answer[i][j]);
            }
            System.out.println();
        }
    }
}

