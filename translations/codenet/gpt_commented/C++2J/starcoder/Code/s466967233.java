import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();
        int[] A = new int[N + 1];
        int[] B = new int[200100];
        Arrays.fill(B, -1);
        int now = 1;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            A[i] = in.nextInt();
        }
        B[1] = 0;
        for (int j = 1; j <= K; j++) {
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

