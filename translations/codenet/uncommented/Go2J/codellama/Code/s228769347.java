
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        int[] ll = new int[n];

        for (int i = 0; i < n; i++) {
            ll[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(ll);

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                }

                ans += l - (j + 1);
            }
        }
        pw.println(ans);

        pw.flush();
    }
}

