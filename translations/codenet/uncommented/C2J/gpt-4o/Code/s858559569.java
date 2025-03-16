import java.util.Scanner;

class Pazz {
    int[][] P = new int[4][4];
}

public class PuzzleSolver {
    static Pazz Q = new Pazz();
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static int Heu(Pazz Q) {
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

    static int dfs(int x, int y, int max, int count, int n) {
        int ans = -1;
        int h = Heu(Q);

        if (h == 0) return count;
        if ((count + h) > max) return -1;

        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i];
            int y0 = y + dy[i];

            if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < 4) && (0 <= y0) && (y0 < 4))) ) continue;

            // Swap the tiles
            int temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;

            ans = dfs(x0, y0, max, count + 1, i);

            if (ans != -1) return ans;

            // Swap back
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int kx = 0, ky = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int a = scanner.nextInt();
                Q.P[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }

        Pazz tP = Q;
        for (int i = 1; i < 46; i++) {
            Q = tP;
            int ans = dfs(kx, ky, i, 0, -1);
            if (ans != -1) {
                System.out.println(ans);
                break;
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
