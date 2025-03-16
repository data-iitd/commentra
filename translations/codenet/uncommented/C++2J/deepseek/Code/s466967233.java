import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[(int) (200100)];
        long[] B = new long[200100];
        Arrays.fill(B, -1);
        int now = 1;
        long cnt = 0;

        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        B[1] = 0;
        for (long j = 1; j <= K; j++) {
            now = (int) A[(int) now];
            if (B[(int) now] == -1) {
                B[(int) now] = j;
            } else {
                cnt = j;
                break;
            }
        }

        if (cnt > 0) {
            long tmp = (K - B[(int) now]) % (cnt - B[(int) now]);
            for (long j = 0; j < tmp; j++) {
                now = (int) A[(int) now];
            }
        }

        System.out.println(now);
    }
}
