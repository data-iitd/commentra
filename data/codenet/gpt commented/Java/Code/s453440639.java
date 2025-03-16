import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the height (H) and width (W) of the grid
        int H = sc.nextInt();
        int W = sc.nextInt();
        sc.nextLine(); // Consume the newline character after the integers
        
        // Initialize a 2D character array to store the grid
        char[][] S = new char[H][W];
        
        // Read the grid input line by line
        for (int i = 0; i < H; i++) {
            String text = sc.nextLine(); // Read a line of input
            // Fill the character array with the characters from the input line
            for (int j = 0; j < W; j++) {
                S[i][j] = text.charAt(j);
            }
        }
        sc.close(); // Close the scanner as we no longer need it

        // Process the grid to count adjacent '#' characters for each '.'
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // Check if the current cell is a '.'
                if (S[i][j] == '.') {
                    int count = 0; // Initialize a counter for adjacent '#' characters
                    // Check all 8 possible directions around the current cell
                    for (int a = -1; a <= 1; a++) {
                        // Ensure we don't go out of bounds vertically
                        if (i + a < 0 || H <= i + a) {
                            continue; // Skip if out of bounds
                        }
                        for (int b = -1; b <= 1; b++) {
                            // Ensure we don't go out of bounds horizontally
                            if (j + b < 0 || W <= j + b) {
                                continue; // Skip if out of bounds
                            }
                            // Count the number of '#' characters in the surrounding cells
                            if (S[i + a][j + b] == '#') {
                                count++;
                            }
                        }
                    }
                    // Replace the '.' with the count of adjacent '#' characters
                    S[i][j] = (char)(count + 48); // Convert count to character ('0' to '8')
                }
                // Print the character (either the count or the original character)
                System.out.printf("%c", S[i][j]);
            }
            // Print a newline after each row of the grid
            System.out.printf("\n");
        }
    }
}
