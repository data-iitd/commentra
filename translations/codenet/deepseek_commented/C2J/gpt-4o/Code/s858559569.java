import java.util.Scanner; // Import the Scanner class for input

class Pazz { // Define a class for the puzzle
    int[][] P = new int[4][4]; // 2D array to store the puzzle state
}

public class PuzzleSolver {
    static Pazz Q = new Pazz(); // Initialize a global variable Q to store the puzzle state
    static int[] dx = {0, 1, 0, -1}; // Define an array for horizontal movement directions
    static int[] dy = {1, 0, -1, 0}; // Define an array for vertical movement directions

    static int Heu(Pazz Q) { // Heuristic function to calculate the Manhattan distance
        int sum = 0;
        for (int i = 0; i < 4; i++) { // Iterate through each row
            for (int j = 0; j < 4; j++) { // Iterate through each column
                if (Q.P[i][j] == 0) continue; // Skip the empty tile

                int hx = (Q.P[i][j] - 1) % 4 - j; // Calculate the horizontal distance
                int hy = (Q.P[i][j] - 1) / 4 - i; // Calculate the vertical distance

                sum += Math.abs(hx) + Math.abs(hy); // Add the distances to the sum
            }
        }
        return sum; // Return the total sum of Manhattan distances
    }

    static int dfs(int x, int y, int max, int count, int n) { // Depth-first search function
        int ans = -1;
        int h = Heu(Q); // Calculate the heuristic value of the current state

        if (h == 0) return count; // If the puzzle is solved, return the number of moves
        if ((count + h) > max) return -1; // If the maximum depth is exceeded, return -1

        for (int i = 0; i < 4; i++) { // Iterate through all possible moves
            int x0 = x + dx[i];
            int y0 = y + dy[i];

            if (((i == (n + 2) % 4) && (n != -1)) || !(0 <= x0 && x0 < 4 && 0 <= y0 && y0 < 4)) continue; // Skip invalid moves

            // Swap the current tile with the target tile
            int temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;

            ans = dfs(x0, y0, max, count + 1, i); // Recursively call dfs with the new state

            if (ans != -1) return ans; // If a solution is found, return the number of moves

            // Swap back to the original state
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }

        return -1; // If no solution is found, return -1
    }

    public static void main(String[] args) { // Main function to read the puzzle, initialize it, and start the DFS search
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int kx = 0, ky = 0, ans;
        Pazz tP = new Pazz();

        for (int i = 0; i < 4; i++) { // Read the puzzle from input
            for (int j = 0; j < 4; j++) {
                int a = scanner.nextInt();
                Q.P[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }

        tP = Q; // Store the initial puzzle state
        for (int i = 1; i < 46; i++) { // Iterate through possible depths
            Q = tP; // Reset Q to the initial state
            ans = dfs(kx, ky, i, 0, -1);
            if (ans != -1) {
                System.out.println(ans); // Print the number of moves if a solution is found
                break;
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
