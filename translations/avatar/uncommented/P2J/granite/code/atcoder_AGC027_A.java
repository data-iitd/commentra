
import java.util.*;
import java.io.*;

class atcoder_AGC027_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int x = Integer.parseInt(s[1]);
        int[] a = new int[n];
        s = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(a);
        int ans = 0;
        if (a[0] > x) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                x = 0;
                break;
            }
            x -= a[i];
            ans += 1;
        }
        if (x!= 0) {
            ans -= 1;
        }
        System.out.println(ans);
    }
}
