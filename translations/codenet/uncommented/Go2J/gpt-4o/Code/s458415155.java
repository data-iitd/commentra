//go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
import java.util.Scanner;

public class Main {
    private static int iabs(int x) {
        return x < 0 ? -x : x;
    }

    private static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            t[i] = Integer.MAX_VALUE;
        }

        t[0] = 0;
        for (int i = 1; i < n; i++) {
            if (t[i - 1] + iabs(heights[i] - heights[i - 1]) < t[i]) {
                t[i] = t[i - 1] + iabs(heights[i] - heights[i - 1]);
            }
            if (i > 1) {
                if (t[i - 2] + iabs(heights[i] - heights[i - 2]) < t[i]) {
                    t[i] = t[i - 2] + iabs(heights[i] - heights[i - 2]);
                }
            }
        }

        return t[n - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }
        int ans = solve(n, heights);
        System.out.println(ans);
        sc.close();
    }
}

//<END-OF-CODE>
