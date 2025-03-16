
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int[] AB = sc.nextInts();
        int A = AB[0];
        int B = AB[1];

        if ((A + B) % 2 == 0) {
            System.out.println((A + B) / 2);
            return;
        }
        System.out.println("IMPOSSIBLE");
    }

    static class Scanner {
        BufferedReader r;
        StringTokenizer t;

        public Scanner() {
            r = new BufferedReader(new InputStreamReader(System.in));
        }

        public int nextInt() {
            int res;
            try {
                res = Integer.parseInt(next());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            return res;
        }

        public int[] nextInts() {
            String[] ss = next().split(" ");
            int[] ints = new int[ss.length];
            for (int i = 0; i < ss.length; i++) {
                ints[i] = Integer.parseInt(ss[i]);
            }
            return ints;
        }

        public String next() {
            while (t == null || !t.hasMoreTokens()) {
                try {
                    t = new StringTokenizer(r.readLine());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return t.nextToken();
        }
    }
}

