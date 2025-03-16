import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.next();
        }
        int[] march = new int[5];
        for (String s : S) {
            if (s.charAt(0) == 'M' || s.charAt(0) == 'A' || s.charAt(0) == 'R' || s.charAt(0) == 'C' || s.charAt(0) == 'H') {
                march[s.charAt(0) - 'M']++;
            }
        }
        int ans = 0;
        for (int x : march) {
            for (int y : march) {
                for (int z : march) {
                    ans += x * y * z;
                }
            }
        }
        System.out.println(ans);
    }
}

