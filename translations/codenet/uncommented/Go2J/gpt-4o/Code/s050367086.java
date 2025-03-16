import java.io.*;
import java.util.*;

public class Main {
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
                while (j >= 0 && s.charAt(i) != s.charAt(j)) {
                    j = table[j];
                }
                j++;
                table[i + 1] = j;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        String s = reader.readLine();
        String t = reader.readLine();

        int ns = s.length();
        int nt = t.length();
        String[] ss = new String[(nt - 1) / ns + 1];

        Arrays.fill(ss, s);
        String sss = String.join("", ss) + String.join("", ss);

        boolean[] ok = new boolean[ns];
        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t);
        int m = 0;

        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }

        for (int i = 0; i < ns; i++) {
            boolean o = true;
            m = 0;
            while (m < nt) {
                if (t.charAt(m) != sss.charAt(i + m)) {
                    o = false;
                    break;
                }
                m++;
            }
            ok[i] = o;
            if (o) {
                i += nt - mp.table[m];
                m = mp.table[m];
            }
            while (m >= 0 && t.charAt(m) != sss.charAt(i + m)) {
                i += m - mp.table[m];
                m = mp.table[m];
            }
            i--;
            m++;
        }

        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (!ok[i]) continue;
            if (!ok[(i + nt) % ns]) continue;
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);
            if (rr == r) {
                writer.println(-1);
                writer.flush();
                return;
            }
            uni[rr] = r;
        }

        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni);
            if (!ok[r]) continue;
            counter[r]++;
        }
        for (int i = 0; i < ns; i++) {
            if (ans < counter[i]) {
                ans = counter[i];
            }
        }

        writer.println(ans);
        writer.flush();
    }

    static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }
        uni[i] = root(uni[i], uni);
        return uni[i];
    }
}
