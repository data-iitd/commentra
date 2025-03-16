import java.util.Scanner;

class Pazz {
    int[][] P = new int[4][4]; // 2D array to hold the puzzle
}

public class PuzzleSolver {
    static Pazz Q = new Pazz(); // Initialize an empty Pazz structure Q
    static int[] dx = {0, 1, 0, -1}; // Define the possible moves in x direction
    static int[] dy = {1, 0, -1, 0}; // Define the possible moves in y direction

    // Function to calculate the heuristic value of the given Pazz structure Q
    static int Heu(Pazz Q) {
        int sum = 0; // Local variable to hold the sum of heuristic values

        // Iterate through all the elements of the 2D array P in Q
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // If the current element is not part of the puzzle, continue to next iteration
                if (Q.P[i][j] == 0) continue;

                // Calculate the heuristic value hx and hy for the current element
                int hx = (Q.P[i][j] - 1) % 4 - j;
                int hy = (Q.P[i][j] - 1) / 4 - i;

                // Update the sum based on the heuristic values hx and hy
                if (hx < 0) sum -= hx;
                else sum += hx;

                if (hy < 0) sum -= hy;
                else sum += hy;
            }
        }
        // Return the final sum as the heuristic value of the given Pazz structure Q
        return sum;
    }

    // Recursive function to find the solution using Depth First Search algorithm
    static int dfs(int x, int y, int max, int count, int n) {
        int ans = -1; // Local variable to store the answer

        // Calculate the heuristic value h of the current Pazz structure Q
        int h = Heu(Q);

        // Base case: If the heuristic value h is 0, return the current count as the solution
        if (h == 0) return count;

        // Check if the current count plus the heuristic value h is greater than the maximum allowed count
        if ((count + h) > max) return -1;

        // Iterate through all the possible moves from the current position (x,y)
        for (int i = 0; i < 4; i++) {
            // Calculate the new position (x0,y0) based on the current position (x,y) and the move i
            int x0 = x + dx[i];
            int y0 = y + dy[i];

            // Check if the new position (x0,y0) is valid or not
            if (((i == (n + 2) % 4) && (n != -1)) || !(0 <= x0 && x0 < 4 && 0 <= y0 && y0 < 4)) continue;

            // Swap the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
            int temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;

            // Recursively call the function dfs with the new position (x0,y0), the maximum allowed count max, the current count+1, and the move i
            ans = dfs(x0, y0, max, count + 1, i);

            // If the function call returns a valid solution, return it
            if (ans != -1) return ans;

            // Swap back the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }

        // If no valid solution is found, return -1
        return -1;
    }

    // Main function to read the input and call the function dfs to find the solution
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int kx = 0, ky = 0; // Local variables to store the position of the empty cell
        int ans; // Local variable to store the answer

        // Initialize an empty Pazz structure Q
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // Read the input and store it in the Pazz structure Q
                int a = scanner.nextInt();
                Q.P[i][j] = a;
                if (a == 0) {
                    kx = j; // Store the position of the empty cell in x direction
                    ky = i; // Store the position of the empty cell in y direction
                }
            }
        }

        // Call the function dfs with the initial position (kx,ky), the maximum allowed count 46, the initial count 0, and the initial move -1
        ans = dfs(kx, ky, 46, 0, -1);

        // If a valid solution is found, print it and exit the program
        if (ans != -1) {
            System.out.println(ans);
            System.exit(0);
        }

        // If no valid solution is found, print an error message and exit the program
        System.out.println("No solution found");
        System.exit(1);
    }
}

// <END-OF-CODE>
