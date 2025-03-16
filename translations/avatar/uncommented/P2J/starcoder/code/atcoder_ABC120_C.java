import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if (s.length() == 1) {
            System.out.println(0);
            return;
        }
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += Math.min(cnt[i], 2);
        }
        System.out.println(ans);
    }
}
