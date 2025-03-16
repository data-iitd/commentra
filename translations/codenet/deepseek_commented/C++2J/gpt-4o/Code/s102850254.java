import java.util.Scanner;

public class Main {
    static int d; // Number of test cases
    static char[][] map = new char[105][105]; // Map to store the grid
    static int n; // Size of the map

    // Function to process the map
    static void visit() {
        int[] dx = {0, 1, 0, -1}; // Direction vectors for x-axis
        int[] dy = {-1, 0, 1, 0}; // Direction vectors for y-axis
        int sum, flg = 0; // Variables to track the sum of steps and the direction flag
        int x = 2, y = n; // Starting position (2, n)
        map[y][x] = ' '; // Mark the starting position as visited
        int[] ab = {2, 2, 2, 2}; // Array to store the previous steps

        // Main loop to process the map
        while (true) {
            sum = 0;
            while (true) {
                if (map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' && map[y + dy[flg]][x + dx[flg]] != ' ') {
                    flg++;
                    break;
                }
                map[y + dy[flg]][x + dx[flg]] = ' '; // Mark the current position as visited
                y += dy[flg]; // Update the y-coordinate
                x += dx[flg]; // Update the x-coordinate
                sum++; // Increment the step count
            }
            if (flg == 4) flg = 0; // Reset the flag if it reaches 4
            if (sum == 0) break; // Break the loop if no steps are taken
            ab[0] = ab[1]; // Update the array with the previous steps
            ab[1] = ab[2];
            ab[2] = sum;
            if (ab[0] == 1 && ab[2] == 1 && ab[1] == 1) break; // Break the loop if the pattern repeats
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        d = scanner.nextInt(); // Read the number of test cases

        for (int l = 0; l < d; l++) {
            n = scanner.nextInt(); // Read the size of the map

            if (n == 1) {
                System.out.println("#"); // Print a single '#' if the size is 1
                if (l != d - 1) System.out.println(); // Add a newline between test cases
                continue;
            }

            // Initialize the map with borders and fill it with '#' and '.'
            for (int i = 0; i <= n + 1; i++) {
                for (int j = 0; j <= n + 1; j++) {
                    map[i][j] = '#';
                    if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = '.';
                }
            }

            visit(); // Call the visit function to process the map

            // Print the processed map
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < map[i].length - 1; j++) {
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
            if (l != d - 1) System.out.println(); // Add a newline between test cases
        }
        scanner.close();
    }
}
// <END-OF-CODE>
