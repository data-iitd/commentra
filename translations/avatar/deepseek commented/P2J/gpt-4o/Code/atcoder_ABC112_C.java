import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<int[]> ls_xyh = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int h = scanner.nextInt();
            ls_xyh.add(new int[]{x, y, h});
        }
        
        System.out.println(solve(n, ls_xyh));
    }

    public static String solve(int n, List<int[]> ls_xyh) {
        int x0 = -1, y0 = -1, h0 = -1;

        // Find the point with a positive height
        for (int i = 0; i < n; i++) {
            if (ls_xyh.get(i)[2] > 0) {
                x0 = ls_xyh.get(i)[0];
                y0 = ls_xyh.get(i)[1];
                h0 = ls_xyh.get(i)[2];
                break;
            }
        }

        // Generate candidate points within a 101x101 grid
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                cands.add(new int[]{cx, cy, h0 + Math.abs(cx - x0) + Math.abs(cy - y0)});
            }
        }

        // Filter candidates to match the height of each point in ls_xyh
        for (int[] point : ls_xyh) {
            int x = point[0];
            int y = point[1];
            int h = point[2];
            cands.removeIf(ch -> Math.max(ch[2] - Math.abs(ch[0] - x) - Math.abs(ch[1] - y), 0) != h);
        }

        // Return the coordinates of the center of the tower
        int[] result = cands.get(0);
        return result[0] + " " + result[1] + " " + result[2];
    }
}
<END-OF-CODE>
