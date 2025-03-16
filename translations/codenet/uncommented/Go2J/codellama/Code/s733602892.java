
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] As = new int[N];
        int[] Fs = new int[N];
        for (int i = 0; i < N; i++) {
            As[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            Fs[i] = sc.nextInt();
        }
        Arrays.sort(As);
        Arrays.sort(Fs);
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            scores[i] = As[i] * Fs[i];
        }
        Arrays.sort(scores);

        int ok = scores[0];
        int ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;

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

