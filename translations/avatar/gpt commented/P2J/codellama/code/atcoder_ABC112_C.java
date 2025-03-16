import java.util.Scanner;

public class Solution {
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

    public static int solve(int n, int[][] ls_xyh) {
        // Initialize the coordinates and height of the first building with a positive height
        int x0 = -1;
        int y0 = -1;
        int h0 = -1;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                y0 = ls_xyh[i][1];
                h0 = ls_xyh[i][2];
                break;
            }
        }

        // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
        int[][] cands = new int[101][101];
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                cands[cx][cy] = h0 + Math.abs(cx - x0) + Math.abs(cy - y0);
            }
        }

        // Filter candidates based on the height constraints from the other buildings
        for (int i = 0; i < n; i++) {
            int x = ls_xyh[i][0];
            int y = ls_xyh[i][1];
            int h = ls_xyh[i][2];
            for (int cx = 0; cx < 101; cx++) {
                for (int cy = 0; cy < 101; cy++) {
                    if (cands[cx][cy] - Math.abs(cx - x) - Math.abs(cy - y) < h) {
                        cands[cx][cy] = -1;
                    }
                }
            }
        }

        // Select the first valid candidate position and height
        int xx = -1;
        int yy = -1;
        int hh = -1;
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                if (cands[cx][cy] > 0) {
                    xx = cx;
                    yy = cy;
                    hh = cands[cx][cy];
                    break;
                }
            }
        }

        // Return the result as a space-separated string
        return xx + " " + yy + " " + hh;
    }
}

