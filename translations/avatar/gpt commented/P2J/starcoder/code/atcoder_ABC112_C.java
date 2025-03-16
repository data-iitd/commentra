import java.util.*;

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
        // Initialize the coordinates and height of the first building with a positive height
        int x0 = -1;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                break;
            }
        }
        if (x0 == -1) {
            return "0 0 0";
        }
        
        // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = Math.max(ls_xyh[0][2] + Math.abs(cx - x0) + Math.abs(cy - ls_xyh[0][1]), 0);
                cands.add(new int[]{cx, cy, ch});
            }
        }
        
        // Filter candidates based on the height constraints from the other buildings
        for (int[] xyh : ls_xyh) {
            List<int[]> newCands = new ArrayList<>();
            for (int[] cand : cands) {
                int cx = cand[0];
                int cy = cand[1];
                int ch = cand[2];
                int x = xyh[0];
                int y = xyh[1];
                int h = xyh[2];
                if (Math.max(ch - Math.abs(cx - x) - Math.abs(cy - y), 0) == h) {
                    newCands.add(cand);
                }
            }
            cands = newCands;
        }
        
        // Select the first valid candidate position and height
        int[] cand = cands.get(0);
        int xx = cand[0];
        int yy = cand[1];
        int hh = cand[2];
        
        // Return the result as a space-separated string
        return xx + " " + yy + " " + hh;
    }
}

