import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static PrintWriter pw;
    static StringTokenizer st;

    static void init() {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    }

    static String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static double nextDouble() {
        return Double.parseDouble(next());
    }

    static char nextChar() {
        return next().charAt(0);
    }

    static String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    static int[] nextIntArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }

    static long[] nextLongArray(int n) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextLong();
        }
        return arr;
    }

    static double[] nextDoubleArray(int n) {
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextDouble();
        }
        return arr;
    }

    static char[] nextCharArray() {
        return nextLine().toCharArray();
    }

    public static void main(String[] args) {
        init();
        char[] S = nextLine().toCharArray();
        int x = nextInt();
        int y = nextInt();

        List<Integer> F = new ArrayList<>();
        int cur = 0;
        for (int i = 0; i < S.length; i++) {
            if (S[i] == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur);
        System.out.println(F);

        List<Integer> evens = new ArrayList<>();
        List<Integer> odds = new ArrayList<>();
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        boolean[][] dpx = new boolean[evens.size() + 1][20000];
        boolean[][] dpy = new boolean[odds.size() + 1][20000];
        dpx[0][10000] = true;
        dpy[0][10000] = true;
        for (int i = 0; i < evens.size(); i++) {
            int val = evens.get(i);
            for (int j = 0; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] |= dpx[i][j];
                }
                if (j - val >= 0) {
                    dpx[i + 1][j - val] |= dpx[i][j];
                }
            }
        }
        for (int i = 0; i < odds.size(); i++) {
            int val = odds.get(i);
            for (int j = 0; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] |= dpy[i][j];
                }
                if (j - val >= 0) {
                    dpy[i + 1][j - val] |= dpy[i][j];
                }
            }
        }

        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            pw.println("Yes");
        } else {
            pw.println("No");
        }
        pw.flush();
    }
}
