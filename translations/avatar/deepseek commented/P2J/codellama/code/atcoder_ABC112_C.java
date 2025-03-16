
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ls_xyh[i][j] = sc.nextInt();
            }
        }
        System.out.println(solve(n, ls_xyh));
    }

    public static String solve(int n, int[][] ls_xyh) {
        // Initialize x0 to None
        int x0 = -1;
        int y0 = -1;
        int h0 = -1;

        // Find the point with a positive height
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                y0 = ls_xyh[i][1];
                h0 = ls_xyh[i][2];
                break;
            }
        }

        // Generate candidate points within a 101x101 grid
        int[][] cands = new int[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                cands[i][j] = h0 + Math.abs(i - x0) + Math.abs(j - y0);
            }
        }

        // Filter candidates to match the height of each point in ls_xyh
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 101; j++) {
                for (int k = 0; k < 101; k++) {
                    if (cands[j][k] < ls_xyh[i][2]) {
                        cands[j][k] = 0;
                    }
                }
            }
        }

        // Return the coordinates of the center of the tower
        int xx = 0;
        int yy = 0;
        int hh = 0;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                if (cands[i][j] > hh) {
                    xx = i;
                    yy = j;
                    hh = cands[i][j];
                }
            }
        }
        return xx + " " + yy + " " + hh;
    }
}

