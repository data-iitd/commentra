import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] As = new int[N];
        int[] Fs = new int[N];

        for (int i = 0; i < N; i++) {
            As[i] = scanner.nextInt();
        }
        for (int i = 0; i < N; i++) {
            Fs[i] = scanner.nextInt();
        }

        Arrays.sort(As);
        Arrays.sort(Fs);
        Collections.reverse(Arrays.asList(Fs));

        long ok = Long.MAX_VALUE;
        long ng = -1;

        while (ok - ng > 1) {
            long mid = (ok + ng) / 2;

            boolean isOK = true;
            int k = K;
            for (int i = 0; isOK && i < N; i++) {
                if (As[i] * Fs[i] > mid) {
                    k -= As[i] - mid / Fs[i];
                }
                if (k < 0) {
                    isOK = false;
                }
            }

            if (isOK) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        System.out.println(ok);
    }
}
