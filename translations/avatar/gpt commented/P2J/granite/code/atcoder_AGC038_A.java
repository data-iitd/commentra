
import java.util.*;

class atcoder_AGC038_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();  // Height of the matrix
        int W = scanner.nextInt();  // Width of the matrix
        int A = scanner.nextInt();  // Column threshold for "0" and "1"
        int B = scanner.nextInt();  // Row threshold for "0" and "1"

        // Initialize a 2D array (matrix) with dimensions H x W filled with "0"
        String[][] answer = new String[H][W];
        for (int i = 0; i < H; i++) {
            Arrays.fill(answer[i], "0");
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

Translate the above Java code to C++ and end with comment "