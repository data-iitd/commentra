
import java.util.*;
import java.io.*;

class s345215315 {
    static int ans = Integer.MAX_VALUE;
    static int h = 19, w = 15;
    static int[] dx = {0, 1, 0, -1, 1, 1, 1, -1, -1};
    static int[] dy = {1, 0, -1, 0, 1, -1, 1, 1, -1};
    static char[][] s = new char[h][w];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < h; i++) {
            s[i] = sc.next().toCharArray();
        }
        int sx = 0, sy = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == 'O') {
                    sx = i;
                    sy = j;
                    s[i][j] = '.';
                }
            }
        }
        dfs(sx, sy, 0);
        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    static void dfs(int x, int y, int cnt) {
        if (cnt > 20) return;
        // System.out.println(x + " " + y + " " + cnt);
        // for (int i = 0; i < h; i++) {
        //     System.out.println(s[i]);
        // }
        if (x == h - 1) {
            ans = Math.min(ans, cnt);
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (s[nx][ny]!= 'X') continue;
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
            while (nx!= x || ny!= y) {
                nx -= dx[i];
                ny -= dy[i];
                s[nx][ny] = 'X';
            }
            s[x][y] = '.';
        }
    }
}
