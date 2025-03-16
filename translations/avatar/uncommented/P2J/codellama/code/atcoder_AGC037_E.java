
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
        String last_dict = get_last_dict(S);
        if (K == 1) {
            System.out.println(last_dict);
        } else {
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (last_dict.charAt(i) == last_dict.charAt(0)) {
                    count++;
                } else {
                    break;
                }
            }
            if (count * (int) Math.pow(2, K - 1) >= N) {
                System.out.println(last_dict.charAt(0) * N);
            } else {
                String S1 = last_dict.charAt(0) + last_dict.substring(0, count * (int) Math.pow(2, K - 1) - 1);
                System.out.println(S1.substring(0, N));
            }
        }
    }

    public static char min(String s) {
        char c = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) < c) {
                c = s.charAt(i);
            }
        }
        return c;
    }

    public static String get_last_dict(String s) {
        String U = s + s.substring(0, s.length() - 1);
        char c = min(s);
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



