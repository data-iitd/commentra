
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class s050367086{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(System.out);

        String s = scanner.next();
        String t = scanner.next();

        int ns = s.length();
        int nt = t.length();
        String[] ss = new String[(nt - 1) / ns + 1];

        for (int i = 0; i < ss.length; i++) {
            ss[i] = s;
        }

        String sss = String.join("", ss) + String.join("", ss);

        boolean[] ok = new boolean[ns];

        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t);
        int m = 0;
        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }
        boolean o = true;
        for (int i = 0; i < ns; i++) {
            o = true;
            for (m = 0; m < nt; m++) {
                if (t.charAt(m)!= sss.charAt(i + m)) {
                    o = false;
                    break;
                }
            }
            ok[i] = o;
            if (o) {
                i += nt - mp.table[m];
                m = mp.table[m];
            }
            while (m >= 0 && t.charAt(m)!= sss.charAt(i + m)) {
                i += m - mp.table[m];
                m = mp.table[m];
            }
            i--;
            m++;
        }

        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (!ok[i]) {
                continue;
            }
            if (!ok[(i + nt) % ns]) {
                continue;
            }
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);
            if (rr == r) {
                out.println(-1);
                out.flush();
                return;
            }
            uni[rr] = r;
        }

        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni);
            if (!ok[r]) {
                continue;
            }
            counter[r]++;
        }
        for (int i = 0; i < ns; i++) {
            if (ans < counter[i]) {
                ans = counter[i];
            }
        }

        out.println(ans);

        out.flush();
    }

    static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }

        uni[i] = root(uni[i], uni);
        return uni[i];
    }

    // MP...
    static class MP {
        String s;
        int[] table;

        void init(String s) {
            this.s = s;
            int n = s.length();
            table = new int[n + 1];
            table[0] = -1;
            int j = -1;
            for (int i = 0; i < n; i++) {
                for (j = j >= 0 && s.charAt(i)!= s.charAt(j)? table[j] : j; j >= 0 && s.charAt(i)!= s.charAt(j); ) {
                    j = table[j];
                }
                j++;
                table[i + 1] = j;
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "