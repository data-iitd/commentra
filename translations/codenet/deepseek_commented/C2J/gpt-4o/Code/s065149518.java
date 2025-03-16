import java.util.Scanner;

public class RobotCollector {
    // Constants
    private static final int MAX = 21;

    // Global variables
    private static int n, x, y;
    private static int[][] fld = new int[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of items to be collected
        while ((n = scanner.nextInt()) != 0) {
            // Initialize the grid and the robot's position
            init(n, scanner);
            // Read the number of movements
            int m = scanner.nextInt();
            // Perform the movements
            move(m, scanner);
            // Output the result
            System.out.println(n == 0 ? "Yes" : "No");
        }
        scanner.close();
    }

    // Initializes the grid with items and sets the robot's starting position
    private static void init(int i, Scanner scanner) {
        // Set the starting position of the robot
        x = y = 10;
        // Clear the grid
        for (int[] row : fld) {
            java.util.Arrays.fill(row, 0);
        }
        // Read the positions of items and mark them in the grid
        while (i-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    // Moves the robot according to the given directions and collects items
    private static void move(int i, Scanner scanner) {
        while (i-- > 0) {
            String direction = scanner.next();
            int a = scanner.nextInt();
            int d = 0;

            // Determine the direction and convert it to an index
            switch (direction.charAt(0)) {
                case 'N':
                    d = 0;
                    break;
                case 'E':
                    d = 1;
                    break;
                case 'S':
                    d = 2;
                    break;
                case 'W':
                    d = 3;
                    break;
            }

            // Move the robot and collect items
            while (a-- > 0) {
                // Update the robot's position based on the direction
                if (d % 2 == 1) {
                    if (d == 1) {
                        x++; // East
                    } else {
                        x--; // West
                    }
                } else {
                    if (d == 0) {
                        y++; // North
                    } else {
                        y--; // South
                    }
                }
                // Check if the robot collects an item
                if (fld[y][x] == 1) {
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}
// <END-OF-CODE>
