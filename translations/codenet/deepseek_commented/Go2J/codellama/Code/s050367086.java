
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        String s = scanner.next();
        String t = scanner.next();

        int ns = s.length();
        int nt = t.length();
        List<String> ss = new ArrayList<>();

        for (int i = 0; i < (nt - 1) / ns + 1; i++) {
            ss.add(s);
        }

        String sss = String.join("", ss) + String.join("", ss);

        boolean[] ok = new boolean[ns];

        int[] uni = new int[ns];
        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }
        int m = 0;
        for (int i = 0; i < ns; i++) {
            boolean o = true;
            for (m = 0; m < nt; m++) {
                if (t.charAt(m) != sss.charAt(i + m)) {
                    o = false;
                    break;
                }
            }
            ok[i] = o;
            if (o) {
                i += nt - m;
                m = m;
            }
            for (m = 0; m >= 0 && t.charAt(m) != sss.charAt(i + m); m = uni[m]) {
                i += m - m;
            }
            i--;
            m++;
        }

        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (ok[i] == false) {
                continue;
            }
            if (ok[(i + nt) % ns] == false) {
                continue;
            }
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);
            if (rr == r) {
                writer.println(-1);
                return;
            }
            uni[rr] = r;
        }

        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            if (ok[i] == false) {
                continue;
            }
            r = root(i, uni);
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

    public static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }

        uni[i] = root(uni[i], uni);
        return uni[i];
    }
}

