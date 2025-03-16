import java.util.*;

public class Main {
    static final long INF = (long) 1e9;
    static final int h = 19, w = 15;
    static char[][] s = new char[h][w]; // 2D array to store the grid
    static long ans = INF;
    static int[] dx = {0, 1, 0, -1, 1, 1, -1, -1};
    static int[] dy = {1, 0, -1, 0, 1, -1, 1, -1};

    // Function to find the greatest common divisor of two numbers
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Function to find the least common multiple of two numbers
    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    // Function to perform a depth-first search from a given position
    // with a given number of steps
    static void dfs(int x, int y, int cnt) {
        // Base case: if the number of steps is greater than 20, return
        if (cnt > 20) return;

        // Check if the current position is the last row of the grid
        if (x == h - 1) {
            // Update the answer if the current number of steps is less than the previous answer
            ans = Math.min(ans, cnt);
            return;
        }

        // Iterate through all the possible directions
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if the next position is out of the grid
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            // Check if the next position contains an 'X'
            if (s[nx][ny] != 'X') continue;

            // Perform a depth-first search from the next position with one more step
            boolean c = true;
            while (c && s[nx][ny] == 'X') {
                s[nx][ny] = '.';
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    if (nx >= h) ans = Math.min(ans, cnt + 1);
                    c = false;
                }
            }

            // If the loop did not exit due to an out-of-grid position, perform the depth-first search
            if (c) dfs(nx, ny, cnt + 1);

            // Backtrack by restoring the previous state of the grid
            while (nx != x || ny != y) {
                nx -= dx[i];
                ny -= dy[i];
                s[nx][ny] = 'X';
            }

            // Restore the current position of the 'O'
            s[x][y] = '.';
        }
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize the 2D array to store the grid
        for (int i = 0; i < h; i++) {
            s[i] = scanner.nextLine().toCharArray();
        }

        // Find the position of the 'O'
        int sx = -1, sy = -1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == 'O') {
                    sx = i;
                    sy = j;
                    s[i][j] = '.';
                }
            }
        }

        // Perform a depth-first search from the position of the 'O' with 0 steps
        dfs(sx, sy, 0);

        // Print the answer if it is not equal to INF
        if (ans == INF) System.out.println(-1);
        else System.out.println(ans);

        scanner.close();
    }
}

// <END-OF-CODE>
