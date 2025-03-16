
import java.util.*;
import java.io.*;

class s410514868 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        long n = Long.parseLong(str[0]);
        long k = Long.parseLong(str[1]);
        String s = br.readLine();
        char L = s.charAt(0);
        long cnt = 0;
        long ans = 0;
        long ans2 = 0;
        for (int i = 1; i < n; i++) {
            if (L == s.charAt(i)) {
                cnt++;
            } else {
                L = s.charAt(i);
                ans += cnt;
                ans2++;
                cnt = 0;
            }
        }
        ans += cnt;
        ans2++;
        System.out.println(ans + Math.min(2 * k, ans2 - 1));
    }
}

