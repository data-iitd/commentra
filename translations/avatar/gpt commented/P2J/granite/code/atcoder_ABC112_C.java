
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
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                int ch = h0 + Math.abs(cx - x0) + Math.abs(cy - y0);
                cands.add(new int[]{cx, cy, ch});
            }
        }

        // Filter candidates based on the height constraints from the other buildings
        for (int i = 0; i < n; i++) {
            int x = ls_xyh[i][0];
            int y = ls_xyh[i][1];
            int h = ls_xyh[i][2];
            List<int[]> newCands = new ArrayList<>();
            for (int[] cand : cands) {
                int cx = cand[0];
                int cy = cand[1];
                int ch = cand[2];
                if (Math.max(ch - Math.abs(cx - x) - Math.abs(cy - y), 0) == h) {
                    newCands.add(cand);
                }
            }
            cands = newCands;
        }

        // Select the first valid candidate position and height
        int[] result = cands.get(0);

        // Return the result as an array of integers
        return result;
    }
}

Translate the above Java code to C++ and end with comment "