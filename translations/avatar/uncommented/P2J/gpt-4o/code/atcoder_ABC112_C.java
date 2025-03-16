import java.util.ArrayList;
import java.util.List;
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
        scanner.close();
    }

    public static String solve(int n, int[][] ls_xyh) {
        Integer x0 = null, y0 = null, h0 = null;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                y0 = ls_xyh[i][1];
                h0 = ls_xyh[i][2];
                break;
            }
        }

        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                cands.add(new int[]{cx, cy, h0 + Math.abs(cx - x0) + Math.abs(cy - y0)});
            }
        }

        for (int[] point : ls_xyh) {
            int x = point[0];
            int y = point[1];
            int h = point[2];
            cands.removeIf(cand -> Math.max(cand[2] - Math.abs(cand[0] - x) - Math.abs(cand[1] - y), 0) != h);
        }

        int[] result = cands.get(0);
        return result[0] + " " + result[1] + " " + result[2];
    }
}
// <END-OF-CODE>
