import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int[] A = new int[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        
        long[] S = new long[N];
        S[0] = A[0];
        for (int i = 1; i < N; i++) {
            S[i] = S[i - 1] + A[i];
        }
        
        long ans = Long.MAX_VALUE;
        for (int k = 1; k <= N / 2; k++) {
            long E = k * X;
            for (int j = N - 2 * k - 1; j >= 0; j -= k) {
                E += 2 * S[j];
            }
            ans = Math.min(ans, E);
        }
        
        System.out.println(ans + N * X + 5 * S[N - 1]);
    }
}
// <END-OF-CODE>
