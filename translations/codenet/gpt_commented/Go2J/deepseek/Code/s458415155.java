import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        int ans = solve(n, heights);
        System.out.println(ans);
    }

    public static int solve(int n, int[] heights) {
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = Integer.MAX_VALUE;
        }

        t[0] = 0;
        for (int i = 1; i < n; i++) {
            if (t[i - 1] + Math.abs(heights[i] - heights[i - 1]) < t[i]) {
                t[i] = t[i - 1] + Math.abs(heights[i] - heights[i - 1]);
            }
            if (i > 1 && t[i - 2] + Math.abs(heights[i] - heights[i - 2]) < t[i]) {
                t[i] = t[i - 2] + Math.abs(heights[i] - heights[i - 2]);
            }
        }

        return t[n - 1];
    }
}
