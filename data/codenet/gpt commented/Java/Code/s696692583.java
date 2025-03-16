import static java.util.Arrays.deepToString;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create an instance of Main and run the main logic
        new Main().run();
    }

    // Helper method to print debug information
    void tr(Object... os) {
        System.err.println(deepToString(os));
    }

    // Scanner to read input from the console
    Scanner sc = new Scanner(System.in);

    public void run() {
        // Continuously read input until there are no more integers
        for (; sc.hasNext();) {
            // Read three integers: two for the player and one for the enemy
            int my1 = sc.nextInt();
            int my2 = sc.nextInt();
            int enemy1 = sc.nextInt();

            // Array to track which numbers have been used
            boolean[] used = new boolean[11];
            used[my1] = true; // Mark the first player's number as used
            used[my2] = true; // Mark the second player's number as used
            used[enemy1] = true; // Mark the enemy's number as used

            // Initialize counters for all available numbers and safe numbers
            int all = 0;
            int safe = 0;

            // Check numbers from 1 to 10 to determine available and safe options
            for (int i = 1; i <= 10; i++) {
                if (!used[i]) {
                    all++; // Count the total available numbers
                    if (my1 + my2 + i <= 20) safe++; // Count safe numbers that keep the sum <= 20
                }
            }

            // Determine if there are enough safe options to win
            if (safe * 2 >= all) {
                System.out.println("YES"); // Output YES if safe options are sufficient
            } else {
                System.out.println("NO"); // Output NO if not enough safe options
            }
        }
    }

    // Method to solve a tic-tac-toe game given a 2D array of moves
    char solve(int[][] a) {
        // Array to represent the players: 'd' for draw, 'o' for player 1, 'x' for player 2
        char[] s = {'d', 'o', 'x'};

        // Check for winning conditions for both players
        for (int side = 1; side <= 2; side++) {
            // Check rows for a win
            for (int i = 0; i < 3; i++) {
                if (a[i][0] == side && a[i][1] == side && a[i][2] == side) return s[side];
                // Check columns for a win
                if (a[0][i] == side && a[1][i] == side && a[2][i] == side) return s[side];
            }
            // Check the main diagonal for a win
            if (a[0][0] == side && a[1][1] == side && a[2][2] == side) return s[side];
            // Check the anti-diagonal for a win
            if (a[0][2] == side && a[1][1] == side && a[2][0] == side) return s[side];
        }

        // Return 'd' for draw if no player has won
        return 'd';
    }
}
