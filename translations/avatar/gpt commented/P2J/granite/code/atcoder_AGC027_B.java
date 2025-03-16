
import java.io.*;
import java.util.*;
import java.util.stream.*;

class atcoder_AGC027_B {
    public static void main(String[] args) throws Exception {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
             PrintWriter out = new PrintWriter(System.out)) {
            String[] split = in.readLine().split(" ");
            int N = Integer.parseInt(split[0]);
            int X = Integer.parseInt(split[1]);
            int[] A = new int[N];
            String[] A_split = in.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(A_split[i]);
            }
            long[] S = new long[N];
            S[0] = A[0];
            for (int i = 1; i < N; i++) {
                S[i] = S[i - 1] + A[i];
            }
            long ans = Long.MAX_VALUE;
            for (int k = 1; k <= N / 3; k++) {
                long E = k * X + 2 * Arrays.stream(S).limit(N - 2 * k - 1).skip((N - 2 * k - 1) % k).boxed().collect(Collectors.summingLong(Long::valueOf));
                ans = Math.min(ans, E);
            }
            out.println(ans + N * X + 5 * S[N - 1]);
        }
    }
}

Translate the above Java code to C++ and end with comment "