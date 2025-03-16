import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cnt = new int[26];
        cnt[0] = 1;
        char[] s = br.readLine().toCharArray();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        long ans = cnt[0];
        for (int i = 1; i < 26; i++) {
            ans *= cnt[i];
            ans %= MOD;
        }
        System.out.println(ans - 1);
    }
}

