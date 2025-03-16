import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] As = readInts(scanner, N);
        int[] Fs = readInts(scanner, N);

        Arrays.sort(As);
        Arrays.sort(Fs);
        reverse(Fs);

        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            scores[i] = As[i] * Fs[i];
        }
        Arrays.sort(scores);
        reverse(scores);

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

    private static int[] readInts(Scanner scanner, int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = scanner.nextInt();
        }
        return ret;
    }

    private static void reverse(int[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            int temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }
}

// <END-OF-CODE>
