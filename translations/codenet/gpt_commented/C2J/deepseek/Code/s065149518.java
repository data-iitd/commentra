import java.util.Scanner;

public class Minesweeper {
    // Constants
    private static final int MAX = 21;

    // Global variables to hold the state of the game
    private static int n, x, y;
    private static char[][] fld = new char[MAX][MAX];

    public static void main(void) {
        Scanner scanner = new Scanner(System.in);
        int m;

        // Continuously read the size of the field until a zero is encountered
        while ((n = scanner.nextInt()) != 0) {
            // Initialize the field based on the size provided
            init(n);
            // Read the number of moves to be made
            m = scanner.nextInt();
            // Execute the moves
            move(m);
            // Print "Yes" if all fields are cleared, otherwise print "No"
            System.out.println(n != 0 ? "No" : "Yes");
        }
        scanner.close();
    }

    // Function to initialize the game field
    private static void init(int i) {
        int a, b;
        // Set the starting position of the player
        x = 10;
        y = 10;
        // Clear the field by setting all values to 0
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                fld[j][k] = 0;
            }
        }
        // Read the positions of obstacles and mark them in the field
        while (i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1; // Mark the position as occupied
        }
    }

    // Function to process the moves made by the player
    private static void move(int i) {
        int a, d;
        char[] buf = new char[2];
        // Process each move command
        while (i-- > 0) {
            // Read the direction and the number of steps
            buf[0] = scanner.next().charAt(0);
            a = scanner.nextInt();
            // Determine the direction based on the input
            switch (buf[0]) {
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
                default:
                    d = -1; // Invalid direction
                    break;
            }
            // Move in the specified direction for the given number of steps
            while (a-- > 0) {
                // Update the position based on the direction
                switch (d) {
                    case 0: // North
                        y--;
                        break;
                    case 1: // East
                        x++;
                        break;
                    case 2: // South
                        y++;
                        break;
                    case 3: // West
                        x--;
                        break;
                }
                // Check if the new position has an obstacle
                if (fld[y][x] == '1') {
                    // Remove the obstacle and decrement the count of remaining obstacles
                    fld[y][x] = '0';
                    n--;
                }
            }
        }
    }
}
