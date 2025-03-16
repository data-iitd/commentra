import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[(int) (200100)];
        long[] B = new long[(int) (200100)];
        int now = 1;
        long cnt = 0;

        // Read array A
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // Initialize B array with -1
        Arrays.fill(B, -1);

        // B[1] is always 0
        B[1] = 0;

        // Simulation of the algorithm
        long j;
        for (j = 1; j <= K; j++) {
            // Move to the next node
            now = (int) A[(int) now];

            // If the node has not been reached yet, update B[now]
            if (B[(int) now] == -1) {
                B[(int) now] = j;
            } else {
                // If the node has already been reached, calculate the answer
                cnt = j;
                break;
            }
        }

        // If the simulation has not reached the end, calculate the answer
        if (j < K) {
            long tmp = (K - B[(int) now]) % (cnt - B[(int) now]);

            // Move to the final node
            for (long jj = 0; jj < tmp; jj++) {
                now = (int) A[(int) now];
            }
        }

        // Print the answer
        System.out.println(now);
    }
}
