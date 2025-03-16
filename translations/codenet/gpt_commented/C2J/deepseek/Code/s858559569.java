import java.util.Scanner;

class Pazz {
    int[][] P = new int[4][4];
}

public class PuzzleSolver {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static int Heu(Pazz Q) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (Q.P[i][j] == 0) continue;
                int hx = (Q.P[i][j] - 1) % 4 - j;
                int hy = (Q.P[i][j] - 1) / 4 - i;
                if (hx < 0) sum -= hx;
                else sum += hx;
                if (hy < 0) sum -= hy;
                else sum += hy;
            }
        }
        return sum;
    }

    public static int dfs(int x, int y, int max, int count, int n, Pazz Q) {
        int ans = -1, h;
        h = Heu(Q);
        if (h == 0) return count;
        if ((count + h) > max) return -1;
        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i];
            int y0 = y + dy[i];
            if (((i == (n + 2) % 4) && (n != -1)) || !(0 <= x0 && x0 < 4 && 0 <= y0 && y0 < 4)) continue;
            int temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
            ans = dfs(x0, y0, max, count + 1, i, Q);
            if (ans != -1) return ans;
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pazz Q = new Pazz();
        int kx = 0, ky = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                Q.P[i][j] = scanner.nextInt();
                if (Q.P[i][j] == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }
        Pazz tP = new Pazz();
        for (int i = 0; i < 4; i++) {
            System.arraycopy(Q.P[i], 0, tP.P[i], 0, 4);
        }
        for (int i = 1; i < 46; i++) {
            for (int j = 0; j < 4; j++) {
                System.arraycopy(tP.P[j], 0, Q.P[j], 0, 4);
            }
            int ans = dfs(kx, ky, i, 0, -1, Q);
            if (ans != -1) {
                System.out.println(ans);
                break;
            }
        }
        scanner.close();
    }
}
