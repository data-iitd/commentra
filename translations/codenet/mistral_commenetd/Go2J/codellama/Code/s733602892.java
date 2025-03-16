
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input: N and K
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Read input: N integers As
        int[] As = new int[N];
        for (int i = 0; i < N; i++) {
            As[i] = sc.nextInt();
        }

        // Read input: N integers Fs
        int[] Fs = new int[N];
        for (int i = 0; i < N; i++) {
            Fs[i] = sc.nextInt();
        }

        // Sort As and Fs in ascending and descending order respectively
        Arrays.sort(As);
        Arrays.sort(Fs);
        for (int i = 0; i < N; i++) {
            Fs[i] = -Fs[i];
        }
        Arrays.sort(Fs);

        // Calculate the score for each element in As
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            scores[i] = As[i] * Fs[i];
        }

        // Sort scores in descending order
        Arrays.sort(scores);

        // Binary search to find the answer
        int ok = scores[0];
        int ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;

            // Check if it's possible to distribute the flowers to K students with the given mid score
            boolean isOK = true;
            int k = K;
            for (int i = 0; isOK && i < N; i++) {
                if (As[i] * Fs[i] > mid) {
                    // Subtract the difference between mid and the product of the current element from the remaining flowers
                    k -= As[i] - mid / Fs[i];
                }
                if (k < 0) {
                    // If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
                    isOK = false;
                    break;
                }
            }

            if (isOK) {
                // If it's possible to distribute the flowers with the given mid score, update ok with mid
                ok = mid;
            } else {
                // If it's not possible to distribute the flowers with the given mid score, update ng with mid
                ng = mid;
            }

        }

        // Print the answer
        System.out.println(ok);
    }
}

