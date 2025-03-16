
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder writer = new StringBuilder();

    private static int N;
    private static long[] T;
    private static long[] A;

    private static long t;
    private static long a;

    public static void main(String[] args) throws IOException {
        N = readInt();
        T = new long[N];
        A = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = readLong();
            A[i] = readLong();
        }
        t = T[0];
        a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max(divUp(t, T[i]), divUp(a, A[i]));
            t = T[i] * r;
            a = A[i] * r;
        }
        writer.append(t + a).append("\n");
        System.out.print(writer);
    }

    private static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    private static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    private static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private static long divUp(long x, long y) {
        return (x + y - 1) / y;
    }

    private static StringTokenizer tokenizer;
}

