import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to solve the problem
    public static String solve(int n, List<int[]> ls_xyh) {
        // Initialize x0 as -1 (indicating not found)
        int x0 = -1, y0 = -1, h0 = -1;

        // Iterate through the list ls_xyh to find the point with the highest height
        for (int i = 0; i < n; i++) {
            if (ls_xyh.get(i)[2] > 0) {  // Check if the height is positive
                x0 = ls_xyh.get(i)[0];  // Assign x0
                y0 = ls_xyh.get(i)[1];  // Assign y0
                h0 = ls_xyh.get(i)[2];  // Assign h0
                break;
            }
        }

        // Generate a list of candidate points based on the given height and the position of x0, y0
        List<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                cands.add(new int[]{cx, cy, h0 + Math.abs(cx - x0) + Math.abs(cy - y0)});
            }
        }

        // Filter out the invalid candidate points based on the given height
        for (int[] point : ls_xyh) {
            int x = point[0], y = point[1], h = point[2];
            cands.removeIf(cand -> Math.max(cand[2] - Math.abs(cand[0] - x) - Math.abs(cand[1] - y), 0) != h);
        }

        // Find the point with the minimum height among the valid candidates
        int[] result = cands.get(0);

        // Return the solution as a string
        return result[0] + " " + result[1] + " " + result[2];
    }

    // Function to read the question and return the problem data
    public static Object[] readQuestion() {
        Scanner scanner = new Scanner(System.in);
        // Read the first line to get the number of points
        int n = Integer.parseInt(scanner.nextLine().trim());

        // Read the second line to get the list of points
        List<int[]> ls_xyh = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            String[] ws = scanner.nextLine().trim().split(" ");
            int[] point = new int[3];
            point[0] = Integer.parseInt(ws[0]);
            point[1] = Integer.parseInt(ws[1]);
            point[2] = Integer.parseInt(ws[2]);
            ls_xyh.add(point);
        }

        // Return the problem data as an array (number of points, list of points)
        return new Object[]{n, ls_xyh};
    }

    // Main function to call the solve function and print the result
    public static void main(String[] args) {
        // Call the readQuestion function to get the problem data
        Object[] data = readQuestion();

        // Call the solve function to get the solution
        String solution = solve((int) data[0], (List<int[]>) data[1]);

        // Print the solution
        System.out.println(solution);
    }
}

// <END-OF-CODE>
