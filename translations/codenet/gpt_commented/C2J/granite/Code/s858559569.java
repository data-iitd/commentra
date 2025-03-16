
import java.util.Scanner;

public class s858559569{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = 4;
        int[][] P = new int[N][N];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int kx, ky, ans, a;
        Pazz tP = new Pazz();

        // Read the puzzle input from the user
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a = scanner.nextInt();
                P[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }

        tP = new Pazz(P);
        // Attempt to solve the puzzle with increasing maximum move limits
        for (int i = 1; i < 46; i++) {
            Pazz Q = new Pazz(tP);
            ans = dfs(Q, kx, ky, i, 0, -1);
            if (ans!= -1) {
                System.out.println(ans);
                break;
            }
        }
    }

    // Define a structure to represent the puzzle state
    static class Pazz {
        int[][] P;

        public Pazz() {
            P = new int[4][4];
        }

        public Pazz(int[][] P) {
            this.P = P;
        }

        public Pazz(Pazz pazz) {
            this.P = new int[4][4];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    this.P[i][j] = pazz.P[i][j];
                }
            }
        }
    }

    // Function to calculate the heuristic value (Manhattan distance) of the puzzle state
    static int Heu(Pazz Q) {
        int i, j;
        int hx, hy, sum = 0;

        // Loop through each cell in the puzzle
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                // Skip the empty tile (represented by 0)
                if (Q.P[i][j] == 0) continue;

                // Calculate the expected position of the tile
                hx = (Q.P[i][j] - 1) % 4 - j; // Horizontal distance
                hy = (Q.P[i][j] - 1) / 4 - i; // Vertical distance

                // Update the sum based on the distances
                if (hx < 0) sum -= hx; // If hx is negative, subtract it from sum
                else sum += hx; // Otherwise, add it to sum

                if (hy < 0) sum -= hy; // If hy is negative, subtract it from sum
                else sum += hy; // Otherwise, add it to sum
            }
        }
        return sum; // Return the total heuristic value
    }

    // Depth-first search function to explore possible moves
    static int dfs(Pazz Q, int x, int y, int max, int count, int n) {
        int i, temp;
        int x0, y0, ans = -1, h;

        // Calculate the heuristic value for the current state
        h = Heu(Q);

        // If the puzzle is solved (heuristic is 0), return the count of moves
        if (h == 0) return count;

        // If the current count plus heuristic exceeds the maximum allowed, return -1
        if ((count + h) > max) return -1;

        // Explore all possible moves
        for (i = 0; i < 4; i++) {
            x0 = x + dx[i]; // Calculate new x position
            y0 = y + dy[i]; // Calculate new y position

            // Check if the move is valid and not reversing the last move
            if (((i == (n + 2) % 4) && (n!= -1)) ||!((0 <= x0) && (x0 < 4) && (0 <= y0) && (y0 < 4))) continue;

            // Swap the empty tile with the adjacent tile
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;

            // Recursively call dfs with the new position
            ans = dfs(Q, x0, y0, max, count + 1, i);

            // If a solution is found, return the answer
            if (ans!= -1) return ans;

            // Swap back to restore the previous state
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }

        return -1; // Return -1 if no solution is found
    }
}

