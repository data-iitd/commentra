import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a = new int[1000][999];
    static int[] e1 = new int[1000000];
    static int[] e2 = new int[1000000];
    static int[] d = new int[1000000];
    static boolean[] b = new boolean[1000000];

    static int p(int a, int b) {
        if (a < b) {
            return a + b * n;
        } else {
            return b + a * n;
        }
    }

    static int f(int from) {
        if (b[from]) return -1;
        if (d[from] != 0) return d[from];
        b[from] = true;
        int to;
        to = e1[from];
        int max = 0;
        if (to != 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        to = e2[from];
        if (to != 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        b[from] = false;
        return d[from] = max + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                a[i][j] = scanner.nextInt() - 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                int from = p(i, a[i][j]);
                int to = p(i, a[i][j + 1]);
                if (e1[from] == 0) {
                    e1[from] = to;
                } else if (e2[from] == 0) {
                    e2[from] = to;
                } else {
                    System.out.println("-1");
                    return;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]);
            int now = f(from);
            if (now < 0) {
                ans = -1;
                break;
            }
            if (now > ans) ans = now;
        }
        System.out.println(ans);
    }
}
// <END-OF-CODE>
