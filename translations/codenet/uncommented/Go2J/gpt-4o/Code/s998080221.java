import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        solve();
    }

    static void solve() throws IOException {
        int N = nextInt();
        int _ = nextInt(); // This variable is not used
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = nextInt();
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

    static int nextInt() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return Integer.parseInt(tokenizer.nextToken());
    }
}

// <END-OF-CODE>
