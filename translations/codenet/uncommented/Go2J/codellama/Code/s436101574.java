
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    static String scanString() { sc.next(); return sc.next(); }
    static int scanInt() { sc.next(); return sc.nextInt(); }
    static long scanLong() { sc.next(); return sc.nextLong(); }
    static double scanDouble() { sc.next(); return sc.nextDouble(); }

    static int[] scanInts(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = scanInt();
        }
        return res;
    }

    static void debug(Object... a) { System.err.println(Arrays.deepToString(a)); }

    static int abs(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }
    static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }
    static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    //•*¨*•.¸¸♪main•*¨*•.¸¸♪(　-ω-)ノ　(　・ω・)
    public static void main(String[] args) {
        wr.flush();
        sc.useDelimiter("\\s+");
        sc.useLocale(Locale.US);

        char[] s = scanString().toCharArray();
        char[] t = scanString().toCharArray();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length - t.length + 1; i++) {
            boolean f = true;
            char[] ss = new char[s.length];
            System.arraycopy(s, 0, ss, 0, s.length);

            for (int j = 0; j < t.length; j++) {
                if (s[i+j] != t[j] && s[i+j] != '?') {
                    f = false;
                    break;
                } else {
                    ss[i+j] = t[j];
                }
            }
            if (f) {
                ans.add(new String(ss).replace("?", "a"));
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            System.out.println("UNRESTORABLE");
        } else {
            System.out.println(ans.get(0));
        }
    }
}

