

import java.io.*;
import java.util.*;

public class codeforces_302_A{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        int sa = 0;
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '-') {
                sa++;
            }
        }
        sa = Math.min(n - sa, sa);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String[] ab = br.readLine().split(" ");
            int a = Integer.parseInt(ab[0]);
            int b = Integer.parseInt(ab[1]);
            b -= a;
            if (b % 2 == 1 && b <= sa * 2) {
                sb.append("1\n");
            } else {
                sb.append("0\n");
            }
        }

        pw.print(sb.toString());
        pw.close();
    }
}

Translate the above Java code to C++ and end with comment "