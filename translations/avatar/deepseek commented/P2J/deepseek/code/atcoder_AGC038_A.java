import java.util.*;

public class Main {
    public static void solve(int H, int W, int A, int B) {
        // Initialize the answer matrix with "0"
        String[][] answer = new String[H][W];
        
        // Fill the matrix based on the given conditions
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < B) {  // Check if the row index is less than B
                    if (j < A) {  // Check if the column index is less than A
                        answer[i][j] = "0";  // Assign "0" if both conditions are met
                    } else {
                        answer[i][j] = "1";  // Assign "1" otherwise
                    }
                } else {  // If the row index is not less than B
                    if (j < A) {
                        answer[i][j] = "1";  // Assign "1" if the column index is less than A
                    } else {
                        answer[i][j] = "0";  // Assign "0" otherwise
                    }
                }
            }
        }
        
        // Print each row of the matrix as a string
        for (int i = 0; i < H; i++) {
            System.out.println(String.join("", answer[i]));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the height
        int H = scanner.nextInt();
        // Read the width
        int W = scanner.nextInt();
        // Read the number of columns to be filled with "0"
        int A = scanner.nextInt();
        // Read the number of rows to be filled with "0"
        int B = scanner.nextInt();
        
        // Call the solve function with the read values
        solve(H, W, A, B);
    }
}
