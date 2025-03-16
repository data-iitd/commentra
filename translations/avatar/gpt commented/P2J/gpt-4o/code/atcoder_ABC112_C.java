import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static String solve(int n, List<int[]> ls_xyh) {
        // Initialize the coordinates and height of the first building with a positive height
        Integer x0 = null, y0 = null, h0 = null;
        for (int i = 0; i < n; i++) {
            if (ls_xyh.get(i)[2] > 0) {
                x0 = ls_xyh.get(i)[0];
                y0 = ls_xyh.get(i)[1];
                h0 = ls_xyh.get(i)[2];
                break;
            }
        }

        // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                cands.add(new int[]{cx, cy, h0 + Math.abs(cx - x0) + Math.abs(cy - y0)});
            }
        }

        // Filter candidates based on the height constraints from the other buildings
        for (int[] building : ls_xyh) {
            int x = building[0];
            int y = building[1];
            int h = building[2];
            cands.removeIf(cand -> Math.max(cand[2] - Math.abs(cand[0] - x) - Math.abs(cand[1] - y), 0) != h);
        }

        // Select the first valid candidate position and height
        int[] result = cands.get(0);

        // Return the result as a space-separated string
        return result[0] + " " + result[1] + " " + result[2];
    }

    public static Object[] readQuestion() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<int[]> ls_xyh = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            int[] building = new int[3];
            building[0] = scanner.nextInt();
            building[1] = scanner.nextInt();
            building[2] = scanner.nextInt();
            ls_xyh.add(building);
        }
        return new Object[]{n, ls_xyh};
    }

    public static void main(String[] args) {
        Object[] input = readQuestion();
        int n = (int) input[0];
        List<int[]> ls_xyh = (List<int[]>) input[1];
        System.out.println(solve(n, ls_xyh));
    }
}

// <END-OF-CODE>
