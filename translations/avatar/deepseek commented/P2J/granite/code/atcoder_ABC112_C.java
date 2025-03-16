

import java.util.*;

public class atcoder_ABC112_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ls_xyh[i][j] = scanner.nextInt();
            }
        }
        int[] result = solve(n, ls_xyh);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);
            if (i < result.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static int[] solve(int n, int[][] ls_xyh) {
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
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = h0 + Math.abs(cx - x0) + Math.abs(cy - y0);
                cands.add(new int[]{cx, cy, ch});
            }
        }

        // Filter candidates to match the height of each point in ls_xyh
        List<int[]> filteredCands = new ArrayList<>();
        for (int[] cand : cands) {
            boolean match = true;
            for (int[] point : ls_xyh) {
                int x = point[0];
                int y = point[1];
                int h = point[2];
                int maxH = Math.max(cand[2] - Math.abs(cand[0] - x) - Math.abs(cand[1] - y), 0);
                if (maxH!= h) {
                    match = false;
                    break;
                }
            }
            if (match) {
                filteredCands.add(cand);
            }
        }

        // Return the coordinates of the center of the tower
        int[] result = filteredCands.get(0);
        return result;
    }
}

Translate the above Java code to C++ and end with comment "