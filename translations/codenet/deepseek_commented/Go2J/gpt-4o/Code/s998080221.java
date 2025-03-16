import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    // Initialize global reader and writer for input and output operations.
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    // Main function calls solve and flushes the writer at the end.
    public static void main(String[] args) throws IOException {
        solve();
    }

    // Solve function implements the main logic of the program.
    private static void solve() throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(st.nextToken());
        int _ = Integer.parseInt(st.nextToken()); // Ignored as it's not used in the logic
        int[] A = new int[N];

        st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];

        for (int i = N - 2; i >= 0; i--) {
            int profit = Math.max(0, maxA - A[i]);
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            maxA = Math.max(maxA, A[i]);
        }

        System.out.println(maxCnt);
    }
}
// <END-OF-CODE>
