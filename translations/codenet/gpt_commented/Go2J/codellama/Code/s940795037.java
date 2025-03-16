
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double ans = 0.0;

        for (int i = 0; i < n; i++) {
            double tmp = 1 / sc.nextInt();
            ans += tmp;
        }

        System.out.println(1 / ans);
    }
}

class Scanner {

    private BufferedReader r;
    private String buf;
    private int p;

    public Scanner(InputStreamReader r) {
        this.r = new BufferedReader(r);
    }

    public String next() {
        pre();
        int start = p;
        while (p < buf.length()) {
            if (buf.charAt(p) == ' ') {
                break;
            }
            p++;
        }
        String result = buf.substring(start, p);
        p++;
        return result;
    }

    public String nextLine() {
        pre();
        int start = p;
        p = buf.length();
        return buf.substring(start);
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public List<Integer> nextIntArray() {
        pre();
        int start = p;
        List<Integer> result = new ArrayList<>();
        while (p < buf.length()) {
            if (buf.charAt(p) == ' ') {
                int v = Integer.parseInt(buf.substring(start, p));
                result.add(v);
                start = p + 1;
            }
            p++;
        }
        int v = Integer.parseInt(buf.substring(start, p));
        result.add(v);
        return result;
    }

    public Map<Integer, Boolean> nextMap() {
        pre();
        int start = p;
        Map<Integer, Boolean> mp = new HashMap<>();
        while (p < buf.length()) {
            if (buf.charAt(p) == ' ') {
                int v = Integer.parseInt(buf.substring(start, p));
                mp.put(v, true);
                start = p + 1;
            }
            p++;
        }
        int v = Integer.parseInt(buf.substring(start, p));
        mp.put(v, true);
        return mp;
    }

    private void pre() {
        if (p >= buf.length()) {
            readLine();
            p = 0;
        }
    }

    private void readLine() {
        buf = "";
        while (true) {
            String l;
            try {
                l = r.readLine();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            buf += l;
            if (!l.endsWith("\\")) {
                break;
            }
        }
    }
}

