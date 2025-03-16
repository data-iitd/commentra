import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
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
        bw.write(ans + "\n");
        bw.flush();
    }
}
