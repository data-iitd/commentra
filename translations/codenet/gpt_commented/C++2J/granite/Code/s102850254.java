
import java.util.Scanner;

public class s102850254{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt(); // Number of test cases
        for (int l = 0; l < d; l++) {
            int n = sc.nextInt(); // Size of the map
            char[][] map = new char[n + 2][n + 2]; // Initialize the map with walls and empty spaces
            for (int i = 0; i <= n + 1; i++) {
                for (int j = 0; j <= n + 1; j++) {
                    map[i][j] = '#'; // Fill the map with walls
                    // Set the border of the map to empty spaces
                    if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = '.';
                }
            }
            int x = 2, y = n; // Starting position on the map
            map[y][x] =''; // Mark the starting position as visited
            int[] ab = new int[4]; // Array to track the last three sums
            int flg = 0, sum = 0; // Initialize flag, sum, and direction
            while (true) {
                sum = 0; // Reset sum for the current direction
                while (true) {
                    // Check if the next position is valid (not a wall and not already visited)
                    if (map[y + (flg == 0? 0 : flg == 1? 2 : flg == 2? 0 : -2)][x + (flg == 0? 2 : flg == 1? 0 : flg == 2? 2 : 0)]!= '#' && map[y + (flg == 0? 1 : flg == 1? 0 : flg == 2? -1 : 1)][x + (flg == 0? 0 : flg == 1? 2 : flg == 2? 0 : -2)]!='') {
                        flg = (flg + 1) % 4; // Change direction
                        break; // Exit the inner loop
                    }
                    // Mark the current position as visited
                    map[y + (flg == 0? 1 : flg == 1? 0 : flg == 2? -1 : 1)][x + (flg == 0? 0 : flg == 1? 2 : flg == 2? 0 : -2)] ='';
                    // Move to the next position
                    y = y + (flg == 0? 1 : flg == 1? 0 : flg == 2? -1 : 1);
                    x = x + (flg == 0? 0 : flg == 1? 2 : flg == 2? 0 : -2);
                    sum++; // Increment the sum of visited positions
                }
                // Reset direction if all 4 directions have been tried
                if (flg == 4) flg = 0;
                // Break the loop if no positions were visited in this direction
                if (sum == 0) break;
                // Update the history of sums
                ab[0] = ab[1];
                ab[1] = ab[2];
                ab[2] = sum;
                // Break if the last three sums are all 1 (indicating a dead end)
                if (ab[0] == 1 && ab[2] == 1 && ab[1] == 1) break;
            }
            // Output the modified map
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < map[i].length - 1; j++) {
                    System.out.print(map[i][j]); // Print each row of the map
                }
                System.out.println(); // Newline after each row
            }
            // Print a newline between test cases if not the last one
            if (l!= d - 1) 
                System.out.println();
        }
    }
}
