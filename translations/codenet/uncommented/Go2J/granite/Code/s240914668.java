
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s240914668{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
                r++;
            }
            ans++;
            i = r;
        }
        out.println(ans);
        out.flush();
    }
}

