import java.util.*;
import java.io.*;

public class Main {
    // Type definitions for convenience
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    // Global variables for the problem
    static int ans = Integer.MAX_VALUE;
    static int h = 19, w = 15;
    static int[] dx = {0, 1, 0, -1, 1, 1, -1, -1};
    static int[] dy = {1, 0, -1, 0, 1, -1, 1, -1};
    static char[][] s = new char[19][15];

    // Depth-First Search (DFS) function to explore the grid
    static void dfs(int x, int y, int cnt) {
        if (cnt > 20) return;
        if (x == h - 1) {
            ans = Math.min(ans, cnt);
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (s[nx][ny] != 'X') continue;
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
            if (c) dfs(nx, ny, cnt + 1);
            while (nx != x || ny != y) {
                nx -= dx[i];
                ny -= dy[i];
                s[nx][ny] = 'X';
            }
            s[x][y] = '.';
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Input the grid
        for (int i = 0; i < h; i++) {
            s[i] = scanner.nextLine().toCharArray();
        }
        int sx = -1, sy = -1;
        // Find the starting position 'O' and mark it as visited
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == 'O') {
                    sx = i;
                    sy = j;
                    s[i][j] = '.';
                }
            }
        }
        // Start DFS from the initial position
        dfs(sx, sy, 0);
        // Output the result: minimum moves or -1 if not reachable
        if (ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
}
