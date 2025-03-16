import java.util.Scanner;

public class Game {
    static final int MAX = 21;
    static int n, x, y;
    static int[][] fld = new int[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            n = scanner.nextInt(); // Read the number of obstacles
            if (n >= 0) { // If n is non-negative, initialize the game and read m
                init(n, scanner);
                int m = scanner.nextInt(); // Read the number of moves
                move(m, scanner);
                System.out.println(n > 0 ? "No" : "Yes"); // Print whether it's possible to make all moves
            } else {
                break; // If n is non-positive, break the loop
            }
        }
        scanner.close();
    }

    static void init(int i, Scanner scanner) { // Initialize the game with n fields
        x = y = 10; // Set the initial position of the player
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                fld[j][k] = 0; // Initialize the field with zeros
            }
        }
        while (i-- > 0) { // Read and store the obstacles' positions
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    static void move(int i, Scanner scanner) { // Move the player i times
        while (i-- > 0) { // Iterate through all moves
            String direction = scanner.next(); // Read the direction
            int a = scanner.nextInt(); // Read the number of steps
            int d = switch (direction.charAt(0)) { // Determine the direction based on the first character
                case 'N' -> 0;
                case 'E' -> 1;
                case 'S' -> 2;
                case 'W' -> 3;
                default -> -1; // Invalid direction
            };
            while (a-- > 0) { // Move the player in the given direction
                if (d % 2 == 1) { // If the direction is odd, move horizontally
                    if (d == 1) {
                        x++; // Move East
                    } else {
                        x--; // Move West
                    }
                } else { // If the direction is even, move vertically
                    if (d == 0) {
                        y++; // Move North
                    } else {
                        y--; // Move South
                    }
                }
                if (fld[y][x] == 1) { // If there's an obstacle at the current position
                    fld[y][x] = 0; // Remove the obstacle
                    n--; // Decrease the number of available moves
                }
            }
        }
    }
}

// <END-OF-CODE>
