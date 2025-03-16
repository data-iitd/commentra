import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }
    }

    public static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        Arrays.fill(t, Integer.MAX_VALUE);
        t[0] = 0;

        for (int i = 1; i < n; i++) {
            int prevIndexCost = t[i - 1];
            if (heights[i] - heights[i - 1] < 0) {
                prevIndexCost += heights[i - 1] - heights[i];
            }
            if (i - 2 >= 0) {
                int prevPrevIndexCost = t[i - 2];
                if (heights[i] - heights[i - 2] < 0) {
                    prevPrevIndexCost += heights[i - 2] - heights[i];
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

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int[] heights = sc.nextIntArray(n);
            int ans = solve(n, heights);
            System.out.println(ans);
        }
    }
}
