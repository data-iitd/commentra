
import java.util.Scanner;

public class s858559569{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] p = new int[4][4];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int n = 4;
        int max = 0;
        int count = 0;
        int ans = -1;
        int x = 0;
        int y = 0;
        int x0 = 0;
        int y0 = 0;
        int temp = 0;
        int i = 0;
        int j = 0;
        int kx = 0;
        int ky = 0;
        int a = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a = scanner.nextInt();
                p[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }

        int[][] tP = new int[4][4];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                tP[i][j] = p[i][j];
            }
        }

        for (i = 1; i < 46; i++) {
            for (j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    p[j][k] = tP[j][k];
                }
            }
            ans = dfs(p, kx, ky, i, 0, -1);
            if (ans!= -1) {
                System.out.println(ans);
                break;
            }
        }
    }

    public static int dfs(int[][] p, int x, int y, int max, int count, int n) {
        int i = 0;
        int temp = 0;
        int x0 = 0;
        int y0 = 0;
        int ans = -1;
        int h = heu(p);

        if (h == 0) {
            return count;
        }
        if ((count + h) > max) {
            return -1;
        }

        for (i = 0; i < 4; i++) {
            x0 = x + dx[i];
            y0 = y + dy[i];

            if (((i == (n + 2) % 4) && (n!= -1)) ||!((0 <= x0) && (x0 < n) && (0 <= y0) && (y0 < n))) {
                continue;
            }
            temp = p[y][x];
            p[y][x] = p[y0][x0];
            p[y0][x0] = temp;

            ans = dfs(p, x0, y0, max, count + 1, i);

            if (ans!= -1) {
                return ans;
            }
            temp = p[y][x];
            p[y][x] = p[y0][x0];
            p[y0][x0] = temp;
        }

        return -1;
    }

    public static int heu(int[][] p) {
        int i = 0;
        int j = 0;
        int hx = 0;
        int hy = 0;
        int sum = 0;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (p[i][j] == 0) {
                    continue;
                }

                hx = (p[i][j] - 1) % 4 - j;
                hy = (p[i][j] - 1) / 4 - i;

                if (hx < 0) {
                    sum -= hx;
                } else {
                    sum += hx;
                }

                if (hy < 0) {
                    sum -= hy;
                } else {
                    sum += hy;
                }
            }
        }

        return sum;
    }
}

