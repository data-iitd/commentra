
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String S = sc.next();
        boolean aaaa = false;
        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }
        if (aaaa) {
            System.out.println(min(S) * N);
            return;
        }
        S = get_last_dict(S);
        if (K == 1) {
            System.out.println(S);
        } else {
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (S.charAt(i) == S.charAt(0)) {
                    count++;
                } else {
                    break;
                }
            }
            if (count * (int) Math.pow(2, K - 1) >= N) {
                System.out.println(S.charAt(0) * N);
            } else {
                S = S.charAt(0) + S.substring(count * (int) Math.pow(2, K - 1), N);
                System.out.println(S);
            }
        }
    }

    public static String get_last_dict(String s_str) {
        String U = s_str + new StringBuilder(s_str).reverse().toString();
        char c = min(s_str);
        int p = U.indexOf(c);
        int minindex = p;
        p++;
        while (p <= N) {
            if (U.charAt(p) == c) {
                if (check_normal_dict(U, minindex, p)) {
                    minindex = p;
                }
            }
            p++;
        }
        return U.substring(minindex, minindex + N);
    }

    public static char min(String s_str) {
        char c = s_str.charAt(0);
        for (int i = 1; i < s_str.length(); i++) {
            if (s_str.charAt(i) < c) {
                c = s_str.charAt(i);
            }
        }
        return c;
    }

    public static boolean check_normal_dict(String u, int pointer1, int pointer2) {
        for (int i = 0; i < N; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}

