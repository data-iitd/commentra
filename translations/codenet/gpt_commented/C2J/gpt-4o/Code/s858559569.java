import java.util.Scanner;

public class PuzzleSolver {
    static final int N = 4; // Size of the puzzle
    static int[][] P = new int[N][N]; // 2D array to hold the puzzle grid
    static int[] dx = {0, 1, 0, -1}; // Movement in the x-direction (right, down, left, up)
    static int[] dy = {1, 0, -1, 0}; // Movement in the y-direction (right, down, left, up)

    // Function to calculate the heuristic value (Manhattan distance) of the puzzle state
    static int Heu() {
        int sum = 0; // Initialize sum

        // Loop through each cell in the puzzle
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Skip the empty tile (represented by 0)
                if (P[i][j] == 0) continue;

                // Calculate the expected position of the tile
                int hx = (P[i][j] - 1) % N - j; // Horizontal distance
                int hy = (P[i][j] - 1) / N - i; // Vertical distance

                // Update the sum based on the distances
                sum += Math.abs(hx) + Math.abs(hy);
            }
        }
        return sum; // Return the total heuristic value
    }

    // Depth-first search function to explore possible moves
    static int dfs(int x, int y, int max, int count, int n) {
        int h = Heu(); // Calculate the heuristic value for the current state

        // If the puzzle is solved (heuristic is 0), return the count of moves
        if (h == 0) return count;

        // If the current count plus heuristic exceeds the maximum allowed, return -1
        if ((count + h) > max) return -1;

        // Explore all possible moves
        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i]; // Calculate new x position
            int y0 = y + dy[i]; // Calculate new y position

            // Check if the move is valid and not reversing the last move
            if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)))) continue;

            // Swap the empty tile with the adjacent tile
            int temp = P[y][x];
            P[y][x] = P[y0][x0];
            P[y0][x0] = temp;

            // Recursively call dfs with the new position
            int ans = dfs(x0, y0, max, count + 1, i);

            // If a solution is found, return the answer
            if (ans != -1) return ans;

            // Swap back to restore the previous state
            temp = P[y][x];
            P[y][x] = P[y0][x0];
            P[y0][x0] = temp;
        }

        return -1; // Return -1 if no solution is found
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int kx = 0, ky = 0; // Variables to hold the position of the empty tile
        int ans; // Variable to hold the answer

        // Read the puzzle input from the user
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                P[i][j] = scanner.nextInt(); // Read each tile value
                if (P[i][j] == 0) { // If the tile is empty
                    kx = j; // Store its x position
                    ky = i; // Store its y position
                }
            }
        }

        // Attempt to solve the puzzle with increasing maximum move limits
        for (int i = 1; i < 46; i++) {
            ans = dfs(kx, ky, i, 0, -1); // Call dfs to find a solution
            if (ans != -1) { // If a solution is found
                System.out.println(ans); // Print the number of moves
                break; // Exit the loop
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
