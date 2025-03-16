
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = 4;
        int[][] P = new int[N][N];
        int[] dx = new int[4];
        int[] dy = new int[4];
        int i, j, kx, ky, ans, a;
        int[][] tP;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                P[i][j] = in.nextInt();
                if (P[i][j] == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }

        tP = new int[N][N];
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tP[i][j] = P[i][j];
            }
        }

        for (i = 1; i < 46; i++) {
            P = tP;
            ans = dfs(kx, ky, i, 0, -1);
            if (ans!= -1) {
                System.out.println(ans);
                break;
            }
        }
    }

    public static int dfs(int x, int y, int max, int count, int n) {
        int i, temp;
        int x0, y0, ans = -1, h;

        h = Heu(P);

        if (h == 0) {
            return count;
        }
        if ((count + h) > max) {
            return -1;
        }

        for (i = 0; i < 4; i++) {
            x0 = x + dx[i];
            y0 = y + dy[i];

            if (((i == (n + 2) % 4) && (n!= -1)) ||!((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N))) {
                continue;
            }
            temp = P[y][x];
            P[y][x] = P[y0][x0];
            P[y0][x0] = temp;

            ans = dfs(x0, y0, max, count + 1, i);

            if (ans!= -1) {
                return ans;
            }
            temp = P[y][x];
            P[y][x] = P[y0][x0];
            P[y0][x0] = temp;
        }

        return -1;
    }

    public static int Heu(int[][] P) {
        int i, j;
        int hx, hy, sum = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (P[i][j] == 0) {
                    continue;
                }

                hx = (P[i][j] - 1) % N - j;
                hy = (P[i][j] - 1) / N - i;

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

