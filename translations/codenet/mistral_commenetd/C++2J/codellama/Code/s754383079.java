
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        int n = a.length();
        String b = sc.next();
        int m = b.length();
        int ans = n + m + 10;
        for (int i = 0; i + m - 1 < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (a.charAt(i + j) != b.charAt(j)) {
                    sum++;
                }
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}

