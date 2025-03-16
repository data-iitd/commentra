import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ls_xyh[i][j] = scanner.nextInt();
            }
        }

        int x0 = -1;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                break;
            }
        }

        int[][] cands = new int[10000][3];
        int candIndex = 0;
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                cands[candIndex][0] = cx;
                cands[candIndex][1] = cy;
                cands[candIndex][2] = ls_xyh[x0][2] + Math.abs(cx - ls_xyh[x0][0]) + Math.abs(cy - ls_xyh[x0][1]);
                candIndex++;
            }
        }

        for (int[] xyh : ls_xyh) {
            int x = xyh[0];
            int y = xyh[1];
            int h = xyh[2];
            for (int i = 0; i < candIndex; i++) {
                int cx = cands[i][0];
                int cy = cands[i][1];
                int ch = cands[i][2];
                if (Math.max(ch - Math.abs(cx - x) - Math.abs(cy - y), 0) != h) {
                    cands[i][2] = -1; // Mark as invalid
                }
            }
        }

        int xx = -1, yy = -1, hh = -1;
        for (int i = 0; i < candIndex; i++) {
            if (cands[i][2] != -1) {
                xx = cands[i][0];
                yy = cands[i][1];
                hh = cands[i][2];
                break;
            }
        }

        System.out.println(xx + " " + yy + " " + hh);
    }
}
