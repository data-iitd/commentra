public class PuzzleSolver {
    static final int N = 4;
    static class Pazz {
        int[][] P = new int[N][N];
    }

    static Pazz Q;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static int Heu(Pazz Q) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (Q.P[i][j] == 0) continue;
                int hx = (Q.P[i][j] - 1) % N - j;
                int hy = (Q.P[i][j] - 1) / N - i;
                if (hx < 0) sum -= hx;
                else sum += hx;
                if (hy < 0) sum -= hy;
                else sum += hy;
            }
        }
        return sum;
    }

    static int dfs(int x, int y, int max, int count, int n) {
        int ans = -1, h;
        h = Heu(Q);
        if (h == 0) return count;
        if (count + h > max) return -1;
        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i];
            int y0 = y + dy[i];
            if (((i == (n + 2) % 4) && (n != -1)) || !(0 <= x0 && x0 < N && 0 <= y0 && y0 < N)) continue;
            int temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
            ans = dfs(x0, y0, max, count + 1, i);
            if (ans != -1) return ans;
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }
        return -1;
    }

    public static void main(String[] args) {
        Q = new Pazz();
        int kx = 0, ky = 0, ans, a;
        Pazz tP = new Pazz();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a = scanner.nextInt();
                Q.P[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }
        tP = Q;
        for (int i = 1; i < 46; i++) {
            Q = tP;
            ans = dfs(kx, ky, i, 0, -1);
            if (ans != -1) {
                System.out.println(ans);
                break;
            }
        }
    }
}
