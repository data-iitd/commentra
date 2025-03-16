import java.util.Scanner;

public class MagicSquare {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int r, c, n, flag, cnt;
        int[][] arr = new int[16][16]; // 2D array to store the magic square

        // Infinite loop to keep the program running until n is 0
        while (true) {
            n = scanner.nextInt(); // Read the size of the magic square from the user
            if (n == 0) {
                break; // Exit the loop if n is 0
            }

            // Initialize the starting position and the counter
            flag = 1;
            r = (n + 1) / 2; // Calculate the starting row (0-based index)
            c = (n + 1) / 2 - 1; // Calculate the starting column (0-based index)
            arr[r][c] = cnt = 1; // Set the initial value and start the counter

            // Loop to fill the magic square
            while (cnt != n * n) {
                ++cnt; // Increment the counter
                if (flag == 1) {
                    r--; // Move up-right
                    c++; // Move up-right
                    if (c >= n) c = 0; // Wrap around if column exceeds n
                    if (r < 0) r = n - 1; // Wrap around if row goes below 0
                    if (arr[r][c] != 0) { // Check if the position is already filled
                        flag = 0; // Change direction
                        --cnt; // Decrement the counter to repeat the last position
                    } else {
                        arr[r][c] = cnt; // Fill the position
                    }
                } else {
                    r++; // Move down-left
                    c--; // Move down-left
                    if (c < 0) c = n - 1; // Wrap around if column goes below 0
                    if (r >= n) r = 0; // Wrap around if row exceeds n
                    if (arr[r][c] != 0) { // Check if the position is already filled
                        flag = 1; // Change direction
                    } else {
                        arr[r][c] = cnt; // Fill the position
                        flag = 1; // Change direction for the next move
                    }
                }
            }

            // Print the generated magic square
            for (r = 0; r < n; r++) {
                for (c = 0; c < n; c++) {
                    System.out.printf("%4d", arr[r][c]); // Print each element with formatting
                    arr[r][c] = 0; // Reset the element for the next iteration
                    if (c == n - 1) {
                        System.out.println(); // Move to the next line after each row
                    }
                }
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
