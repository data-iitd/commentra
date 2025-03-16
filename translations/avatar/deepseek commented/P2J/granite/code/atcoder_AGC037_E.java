

import java.util.Scanner;

public class atcoder_AGC037_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();
        boolean aaaa = false;
        if (k >= 15 || Math.pow(2, k) >= n) {
            aaaa = true;
        }
        if (aaaa) {
            System.out.println(String.valueOf(s.charAt(0)).repeat(Math.max(0, n)));
            return;
        }
        String u = s + new StringBuilder(s).reverse().toString();
        char c = s.charAt(0);
        int minIndex = u.indexOf(c);
        int p = minIndex + 1;
        while (p <= n) {
            if (u.charAt(p) == c) {
                if (checkNormalDict(u, minIndex, p)) {
                    minIndex = p;
                }
            }
            p++;
        }
        String result = u.substring(minIndex, minIndex + n);
        if (k == 1) {
            System.out.println(result);
            return;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == s.charAt(0)) {
                count++;
            } else {
                break;
            }
        }
        if (count * Math.pow(2, k - 1) >= n) {
            System.out.println(String.valueOf(s.charAt(0)).repeat(Math.max(0, n)));
            return;
        }
        String newS = String.valueOf(s.charAt(0)).repeat(count * ((int) Math.pow(2, k - 1) - 1)) + s;
        System.out.println(newS.substring(0, n));
    }

    private static boolean checkNormalDict(String u, int pointer1, int pointer2) {
        for (int i = 0; i < n; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}

Translate the above Java code to C++ and end with comment "