
import java.util.*;
import java.io.*;

public class s466967233{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        int[] A = new int[N + 1];
        int[] B = new int[N + 1];
        int now = 1;
        int cnt = 0;
        int j;

        input = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(input[i - 1]);
        }

        for (int i = 1; i <= N; i++) {
            B[i] = -1;
        }

        B[1] = 0;

        for (j = 1; j <= K; j++) {
            now = A[now];
            if (B[now] == -1) {
                B[now] = j;
            } else {
                cnt = j;
                break;
            }
        }

        if (j < K) {
            int tmp;
            tmp = (K - B[now]) % (cnt - B[now]);
            for (int j = 0; j < tmp; j++) {
                now = A[now];
            }
        }

        System.out.println(now);
    }
}
