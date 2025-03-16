
import java.util.*;
import java.io.*;

class codeforces_350_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] t = new int[n+1];
        int[] a = new int[n+1];
        String[] s = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            t[i] = Integer.parseInt(s[i-1]);
        }
        s = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(s[i-1]);
        }
        int[] cnt = new int[n+1];
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        List<Integer> ans = new ArrayList<>();
        int[] crt = new int[n+1];
        int crt_len = 0;
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {
                crt_len = 0;
                int x = a[i];
                crt[crt_len++] = i;
                while (cnt[x] == 1) {
                    crt[crt_len++] = x;
                    x = a[x];
                }
                if (crt_len > ans.size()) {
                    ans.clear();
                    for (int j = 0; j < crt_len; j++) {
                        ans.add(crt[j]);
                    }
                }
            }
        }
        Collections.reverse(ans);
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i));
            if (i < ans.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
