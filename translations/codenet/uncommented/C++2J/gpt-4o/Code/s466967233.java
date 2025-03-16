import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[200100];
        long[] B = new long[200100];
        for (int i = 0; i < 200100; i++) {
            B[i] = -1;
        }
        int now = 1;
        long cnt = 0;

        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        B[1] = 0;
        long j;
        for (j = 1; j <= K; j++) {
            now = (int) A[now];
            if (B[now] == -1) {
                B[now] = j;
            } else {
                cnt = j;
                break;
            }
        }

        if (j < K) {
            long tmp = (K - B[now]) % (cnt - B[now]);
            for (long k = 0; k < tmp; k++) {
                now = (int) A[now];
            }
        }

        System.out.println(now);
        scanner.close();
    }
}
// <END-OF-CODE>
