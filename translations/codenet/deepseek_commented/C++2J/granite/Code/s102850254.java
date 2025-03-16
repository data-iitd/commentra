
import java.util.Scanner;

public class s102850254{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt(); // Number of test cases
        for (int l = 0; l < d; l++) {
            int n = sc.nextInt(); // Size of the map
            char[][] map = new char[n + 2][n + 2]; // Map to store the grid
            for (int i = 0; i <= n + 1; i++) {
                for (int j = 0; j <= n + 1; j++) {
                    map[i][j] = '#';
                    if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = '.';
                }
            }

            // Function to process the map
            void visit() {
                int[] dx = {0, 1, 0, -1}; // Direction vectors for x-axis
                int[] dy = {-1, 0, 1, 0}; // Direction vectors for y-axis
                int sum, flg = 0; // Variables to track the sum of steps and the direction flag
                int x = 2, y = n; // Starting position (2, n)
                map[y][x] =''; // Mark the starting position as visited
                int[] ab = {2, 2, 2}; // Array to store the previous steps

                // s102850254 loop to process the map
                while (true) {
                    sum = 0;
                    while (true) {
                        if (map[y + dy[flg] * 2][x + dx[flg] * 2]!= '#' && map[y + dy[flg]][x + dx[flg]]!='') {
                            flg++;
                            break;
                        }
                        map[y + dy[flg]][x + dx[flg]] =''; // Mark the current position as visited
                        y = y + dy[flg]; // Update the y-coordinate
                        x = x + dx[flg]; // Update the x-coordinate
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

            visit(); // Call the visit function to process the map

            // Print the processed map
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < map[i].length - 1; j++) {
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
            if (l!= d - 1) System.out.println(); // Add a newline between test cases
        }
    }
}

