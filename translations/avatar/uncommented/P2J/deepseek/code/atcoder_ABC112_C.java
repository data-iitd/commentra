import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            ls_xyh[i][0] = scanner.nextInt();
            ls_xyh[i][1] = scanner.nextInt();
            ls_xyh[i][2] = scanner.nextInt();
        }
        System.out.println(solve(n, ls_xyh));
    }

    public static String solve(int n, int[][] ls_xyh) {
        int x0 = -1;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                break;
            }
        }

        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                int h0 = ls_xyh[x0][2] + Math.abs(ls_xyh[x0][0] - x0) + Math.abs(ls_xyh[x0][1] - cy);
                boolean valid = true;
                for (int i = 0; i < n; i++) {
                    int h = ls_xyh[i][2] + Math.abs(ls_xyh[i][0] - cx) + Math.abs(ls_xyh[i][1] - cy);
                    if (Math.max(h0 - Math.abs(ls_xyh[i][0] - cx) - Math.abs(ls_xyh[i][1] - cy), 0) != ls_xyh[i][2]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    return cx + " " + cy + " " + h0;
                }
            }
        }
        return "";
    }
}
