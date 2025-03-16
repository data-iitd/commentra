
import java.util.*;

public class Tower {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ls_xyh[i][j] = in.nextInt();
            }
        }
        System.out.println(solve(n, ls_xyh));
    }
    
    public static String solve(int n, int[][] ls_xyh) {
        // Initialize x0 to None
        int x0 = -1;
        
        // Find the point with a positive height
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                break;
            }
        }
        
        // Generate candidate points within a 101x101 grid
        List<int[]> cands = new ArrayList<int[]>();
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = Math.max(0, ls_xyh[0][2] + Math.abs(cx - x0) + Math.abs(cy - ls_xyh[0][1]));
                for (int i = 1; i < n; i++) {
                    ch = Math.max(0, ch - Math.max(0, ls_xyh[i][2] + Math.abs(cx - ls_xyh[i][0]) + Math.abs(cy - ls_xyh[i][1])));
                }
                cands.add(new int[]{cx, cy, ch});
            }
        }
        
        // Return the coordinates of the center of the tower
        int[] ans = cands.get(0);
        return String.format("%d %d %d", ans[0], ans[1], ans[2]);
    }
}

