import java.io.*;
import java.util.*;

public class Main {
    public static void solve(long N, List<Long> T, long M, List<Long> P, List<Long> X) {
        for (int i = 0; i < M; i++) {
            long ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == P.get(i) - 1) ans += X.get(i);
                else ans += T.get(j);
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        List<Long> T = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            T.add(Long.parseLong(br.readLine()));
        }
        long M = Long.parseLong(br.readLine());
        List<Long> P = new ArrayList<>();
        List<Long> X = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String[] s = br.readLine().split(" ");
            P.add(Long.parseLong(s[0]));
            X.add(Long.parseLong(s[1]));
        }
        solve(N, T, M, P, X);
    }
}

