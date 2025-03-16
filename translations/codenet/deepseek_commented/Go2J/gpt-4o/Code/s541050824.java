import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    // BufferedReader for efficient input
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter writer = new PrintWriter(System.out);
    private static StringTokenizer tokenizer;

    // Main function
    public static void main(String[] args) throws IOException {
        solve();
        writer.flush();
    }

    // Solve function
    // Reads the number of elements N.
    // Reads N pairs of integers T and A.
    // Iteratively adjusts t and a to ensure the ratios are maintained.
    // Outputs the sum of t and a after all adjustments.
    private static void solve() throws IOException {
        long N = nextInt();
        long[] T = new long[(int) N];
        long[] A = new long[(int) N];
        
        for (int i = 0; i < N; i++) {
            T[i] = nextInt();
            A[i] = nextInt();
        }
        
        long t = T[0], a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max(divUp(t, T[i]), divUp(a, A[i]));
            t = T[i] * r;
            a = A[i] * r;
        }
        
        out(t + a);
    }

    // Reads the next integer from input
    private static long nextInt() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return Long.parseLong(tokenizer.nextToken());
    }

    // Outputs the arguments to the output with a newline
    private static void out(long result) {
        writer.println(result);
    }

    // Returns the ceiling of the division of x by y
    private static long divUp(long x, long y) {
        return (x + y - 1) / y;
    }
}

// <END-OF-CODE>
