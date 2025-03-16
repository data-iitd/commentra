import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] a = new int[26];
        for (int i = 0; i < s.length(); i++) {
            a[s.charAt(i) - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += Math.min(a[i], 1) * 2;
        }
        System.out.println(ans);
    }
}

