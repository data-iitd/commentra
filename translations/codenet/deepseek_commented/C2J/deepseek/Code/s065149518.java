import java.util.Scanner;

public class Robot {
    static final int MAX = 21;

    // Function prototypes
    static void init(int n);
    static void move(int m);

    // Global variables
    static int n, x, y;
    static int[][] fld = new int[MAX][MAX];

    public static void main(void) {
        Scanner scanner = new Scanner(System.in);
        int m;
        // Read the number of items to be collected
        while((n = scanner.nextInt()) != 0) {
            // Initialize the grid and the robot's position
            init(n);
            // Read the number of movements
            m = scanner.nextInt();
            // Perform the movements
            move(m);
            // Output the result
            System.out.println(n == 0 ? "Yes" : "No");
        }
        scanner.close();
    }

    // Initializes the grid with items and sets the robot's starting position
    static void init(int i) {
        int a, b;
        // Set the starting position of the robot
        x = 10;
        y = 10;
        // Clear the grid
        for (int[] row : fld) {
            java.util.Arrays.fill(row, 0);
        }
        // Read the positions of items and mark them in the grid
        while(i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    // Moves the robot according to the given directions and collects items
    static void move(int i) {
        int a, d;
        String buf;
        // Read each movement and execute it
        while(i-- > 0) {
            buf = scanner.next();
            a = scanner.nextInt();
            // Determine the direction and convert it to an index
            switch(buf) {
              case "N":
                d = 0;
                break;
              case "E":
                d = 1;
                break;
              case "S":
                d = 2;
                break;
              case "W":
                d = 3;
                break;
              default:
                d = -1; // This should never happen
                break;
            }
            // Move the robot and collect items
            while(a-- > 0) {
                // Update the robot's position based on the direction
                switch(d) {
                  case 0: // North
                    x--;
                    break;
                  case 1: // East
                    y++;
                    break;
                  case 2: // South
                    x++;
                    break;
                  case 3: // West
                    y--;
                    break;
                }
                // Check if the robot collects an item
                if(fld[x][y] == 1) {
                    fld[x][y] = 0;
                    n--;
                }
            }
        }
    }
}
