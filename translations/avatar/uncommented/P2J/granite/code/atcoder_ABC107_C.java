
import java.util.*;
import java.io.*;

class atcoder_ABC107_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int[] a = new int[n];
        s = br.readLine().split(" ");
        int p = 0, m = 0;
        int[] pos = new int[n];
        int[] neg = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);
            if (a[i] > 0) {
                pos[p++] = a[i];
            } else if (a[i] < 0) {
                neg[m++] = a[i];
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            if (i > p || k - i > m) {
                continue;
            }
            int tmp = 0;
            if (i > 0) {
                tmp += pos[i - 1];
            }
            if (k - i > 0) {
                tmp += neg[m - (k - i)];
            }
            tmp = Math.max(tmp, Math.abs(tmp));
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans * 2);
    }
}
