import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    // Computes 2^a
    public static int pow2(int a) {
        int ret = 1;
        for (int i = 0; i < a; i++) ret *= 2;
        return ret;
    }

    // Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
    public static int count(List<List<Integer>> hw, int a, int b) {
        int sum = 0;
        for (int i = 0; i < hw.size(); i++) {
            for (int j = 0; j < hw.get(0).size(); j++) {
                if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw.get(i).get(j) == 1) sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize the grid with dimensions h x w, filled with 0s
        List<List<Integer>> hw = new ArrayList<>();
        for (int i = 0; i < h; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < w; j++) {
                row.add(0);
            }
            hw.add(row);
        }

        // Read the grid and set 1s where there is a '#'
        for (int i = 0; i < h; i++) {
            String row = scanner.next();
            for (int j = 0; j < w; j++) {
                if (row.charAt(j) == '#') {
                    hw.get(i).set(j, 1);
                }
            }
        }

        int sum = 0;

        // Iterate over all possible combinations of row and column selections
        for (int i = 0; i < pow2(h); i++) {
            for (int j = 0; j < pow2(w); j++) {
                if (count(hw, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
            }
        }

        // Output the result
        System.out.println(sum);
    }
}
