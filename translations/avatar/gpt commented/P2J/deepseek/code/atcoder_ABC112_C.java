import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static String solve(int n, List<List<Integer>> ls_xyh) {
        // Initialize the coordinates and height of the first building with a positive height
        int x0 = -1;
        int y0 = -1;
        int h0 = -1;
        for (int i = 0; i < n; i++) {
            if (ls_xyh.get(i).get(2) > 0) {
                x0 = ls_xyh.get(i).get(0);
                y0 = ls_xyh.get(i).get(1);
                h0 = ls_xyh.get(i).get(2);
                break;
            }
        }

        // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
        List<List<Integer>> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                int ch = h0 + Math.abs(cx - x0) + Math.abs(cy - y0);
                List<Integer> cand = new ArrayList<>();
                cand.add(cx);
                cand.add(cy);
                cand.add(ch);
                cands.add(cand);
            }
        }

        // Filter candidates based on the height constraints from the other buildings
        for (int i = 0; i < n; i++) {
            int x = ls_xyh.get(i).get(0);
            int y = ls_xyh.get(i).get(1);
            int h = ls_xyh.get(i).get(2);
            cands.removeIf(cand -> Math.max(cand.get(2) - Math.abs(cand.get(0) - x) - Math.abs(cand.get(1) - y), 0) != h);
        }

        // Select the first valid candidate position and height
        int xx = cands.get(0).get(0);
        int yy = cands.get(0).get(1);
        int hh = cands.get(0).get(2);

        // Return the result as a space-separated string
        return xx + " " + yy + " " + hh;
    }

    public static List<List<Integer>> readQuestion() {
        Scanner scanner = new Scanner(System.in);
        String[] ws = scanner.nextLine().strip().split(" ");
        int n = Integer.parseInt(ws[0]);
        List<List<Integer>> ls_xyh = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            String[] line = scanner.nextLine().strip().split(" ");
            List<Integer> xyh = new ArrayList<>();
            for (String s : line) {
                xyh.add(Integer.parseInt(s));
            }
            ls_xyh.add(xyh);
        }
        scanner.close();
        return ls_xyh;
    }

    public static void main(String[] args) {
        // Execute the solve function with the input read from readQuestion and print the result
        System.out.println(solve(readQuestion().size(), readQuestion()));
    }
}
