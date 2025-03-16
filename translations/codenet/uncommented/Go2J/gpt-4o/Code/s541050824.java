import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter writer = new PrintWriter(System.out);
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        solve();
        writer.flush();
    }

    static void solve() throws IOException {
        long N = nextLong();
        long[] T = new long[(int) N];
        long[] A = new long[(int) N];
        
        for (int i = 0; i < N; i++) {
            T[i] = nextLong();
            A[i] = nextLong();
        }
        
        long t = T[0], a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max(divUp(t, T[i]), divUp(a, A[i]));
            t = T[i] * r;
            a = A[i] * r;
        }
        
        writer.println(t + a);
    }

    static long nextLong() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return Long.parseLong(tokenizer.nextToken());
    }

    static long divUp(long x, long y) {
        return (x + y - 1) / y;
    }
}

// <END-OF-CODE>
