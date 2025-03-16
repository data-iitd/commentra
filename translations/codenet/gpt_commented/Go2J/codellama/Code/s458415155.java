
// <START-OF-CODE>
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }
        System.out.println(solve(n, heights));
    }

    private static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }
        t[0] = 0;
        for (int i = 1; i < n; i++) {
            int v = t[i - 1] + Math.abs(heights[i] - heights[i - 1]);
            if (v < t[i]) {
                t[i] = v;
            }
            if (i > 1) {
                v = t[i - 2] + Math.abs(heights[i] - heights[i - 2]);
                if (v < t[i]) {
                    t[i] = v;
                }
            }
        }
        return t[n - 1];
    }
}
// 