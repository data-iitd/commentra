
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s846000843{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int[] cumsum = new int[n + 1];
        cumsum[0] = 0;
        for (int i = 0; i < n; i++) {
            cumsum[i + 1] = cumsum[i] + a[i];
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[n] - 2 * cumsum[i + 1]));
        }

        out.println(ans);
        out.flush();
    }
}

// 