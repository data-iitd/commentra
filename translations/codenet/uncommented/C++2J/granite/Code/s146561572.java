
import java.util.*;
import java.io.*;

public class s146561572{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long ans = 0;
            // Contribution of The Nodes.
            for (int i = 1; i <= n; i++) {
                ans += i * 1l * (n - i + 1);
            }
            for (int i = 1; i < n; i++) {
                String[] str = br.readLine().split(" ");
                int u = Integer.parseInt(str[0]);
                int v = Integer.parseInt(str[1]);
                int a = Math.max(u, v);
                int b = Math.min(u, v);
                ans -= b * 1l * (n - a + 1);
            }
            out.println(ans);
        }
        br.close();
        out.close();
    }
}

