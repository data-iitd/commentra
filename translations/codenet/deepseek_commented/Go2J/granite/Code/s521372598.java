
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s521372598{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] as = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            as[i] = Integer.parseInt(st.nextToken());
        }

        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1;
        }
        Arrays.sort(xs);

        int b = xs[n / 2];
        int ans = 0;
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        pw.println(ans);
        pw.flush();
    }
}

// The abs function returns the absolute value of an integer n.
private static int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

private static final int MOD = 1_000_000_007;

// -----------------------------------------

private static final int[] dx = {0, 1, 0, -1};
private static final int[] dy = {-1, 0, 1, 0};

// -----------------------------------------

private static final String END_OF_CODE = "