
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int[] heights = new int[n];
            for (int j = 0; j < n; j++) {
                heights[j] = sc.nextInt();
            }
            System.out.println(solve(n, heights));
        }
    }

    public static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }
        t[0] = 0;
        for (int i = 1; i < n; i++) {
            int prevIndexCost = t[i - 1];
            if (heights[i] - heights[i - 1] < 0) {
                prevIndexCost += heights[i] - heights[i - 1];
            } else {
                prevIndexCost -= heights[i] - heights[i - 1];
            }
            if (i - 2 >= 0) {
                int prevPrevIndexCost = t[i - 2];
                if (heights[i] - heights[i - 2] < 0) {
                    prevPrevIndexCost += heights[i] - heights[i - 2];
                } else {
                    prevPrevIndexCost -= heights[i] - heights[i - 2];
                }
                if (prevIndexCost < t[i]) {
                    t[i] = prevIndexCost;
                }
                if (prevPrevIndexCost < t[i]) {
                    t[i] = prevPrevIndexCost;
                }
            } else {
                if (prevIndexCost < t[i]) {
                    t[i] = prevIndexCost;
                }
            }
        }
        return t[n - 1];
    }
}

