import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static String solve(int n, List<List<Integer>> ls_xyh) {
        // Initialize x0 to None
        Integer x0 = null;
        
        // Find the point with a positive height
        for (int i = 0; i < n; i++) {
            if (ls_xyh.get(i).get(2) > 0) {
                x0 = ls_xyh.get(i).get(0);
                int y0 = ls_xyh.get(i).get(1);
                int h0 = ls_xyh.get(i).get(2);
                break;
            }
        }
        
        // Generate candidate points within a 101x101 grid
        List<List<Integer>> cands = new ArrayList<>();
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                int ch = h0 + Math.abs(cx - x0) + Math.abs(cy - y0);
                List<Integer> cand = new ArrayList<>();
                cand.add(cx);
                cand.add(cy);
                cand.add(ch);
                cands.add(cand);
            }
        }
        
        // Filter candidates to match the height of each point in ls_xyh
        for (List<Integer> point : ls_xyh) {
            int x = point.get(0);
            int y = point.get(1);
            int h = point.get(2);
            cands.removeIf(cand -> Math.max(cand.get(2) - Math.abs(cand.get(0) - x) - Math.abs(cand.get(1) - y), 0) != h);
        }
        
        // Return the coordinates of the center of the tower
        int xx = cands.get(0).get(0);
        int yy = cands.get(0).get(1);
        int hh = cands.get(0).get(2);
        return xx + " " + yy + " " + hh;
    }

    public static List<List<Integer>> readQuestion() {
        Scanner scanner = new Scanner(System.in);
        String[] ws = scanner.nextLine().strip().split(" ");
        int n = Integer.parseInt(ws[0]);
        List<List<Integer>> ls_xyh = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            String[] line = scanner.nextLine().strip().split(" ");
            List<Integer> point = new ArrayList<>();
            for (String s : line) {
                point.add(Integer.parseInt(s));
            }
            ls_xyh.add(point);
        }
        return ls_xyh;
    }

    public static void main(String[] args) {
        // Read input, solve the problem, and print the result
        System.out.println(solve(readQuestion().size(), readQuestion()));
    }
}
