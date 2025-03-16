import java.util.Scanner;

public class Game {
    // Constants
    private static final int MAX = 21;

    // Global variables to hold the state of the game
    private static int n, x, y;
    private static int[][] fld = new int[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Continuously read the size of the field until a zero is encountered
        while ((n = scanner.nextInt()) != 0) {
            // Initialize the field based on the size provided
            init(n, scanner);
            // Read the number of moves to be made
            int m = scanner.nextInt();
            // Execute the moves
            move(m, scanner);
            // Print "Yes" if all fields are cleared, otherwise print "No"
            System.out.println(n == 0 ? "Yes" : "No");
        }
        scanner.close();
    }

    // Function to initialize the game field
    private static void init(int i, Scanner scanner) {
        // Set the starting position of the player
        x = y = 10;
        // Clear the field by setting all values to 0
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                fld[j][k] = 0;
            }
        }
        // Read the positions of obstacles and mark them in the field
        while (i-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            fld[b][a] = 1; // Mark the position as occupied
        }
    }

    // Function to process the moves made by the player
    private static void move(int i, Scanner scanner) {
        while (i-- > 0) {
            String direction = scanner.next();
            int steps = scanner.nextInt();
            int d = 0;

            // Determine the direction based on the input
            switch (direction.charAt(0)) {
                case 'N':
                    d = 0; // North
                    break;
                case 'E':
                    d = 1; // East
                    break;
                case 'S':
                    d = 2; // South
                    break;
                case 'W':
                    d = 3; // West
                    break;
            }

            // Move in the specified direction for the given number of steps
            while (steps-- > 0) {
                // Update the position based on the direction
                if (d % 2 == 1) {
                    if (d == 1) {
                        x++; // East
                    } else {
                        x--; // West
                    }
                } else {
                    if (d == 0) {
                        y--; // North
                    } else {
                        y++; // South
                    }
                }

                // Check if the new position has an obstacle
                if (fld[y][x] == 1) {
                    // Remove the obstacle and decrement the count of remaining obstacles
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}
// <END-OF-CODE>
