import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[200100];
        long[] B = new long[200100];
        for (int i = 0; i < 200100; i++) {
            B[i] = -1; // Initialize B array with -1
        }
        int now = 1;
        long cnt = 0;

        // Read array A
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // B[1] is always 0
        B[1] = 0;

        // Simulation of the algorithm
        long j;
        for (j = 1; j <= K; j++) {
            // Move to the next node
            now = (int) A[now];

            // If the node has not been reached yet, update B[now]
            if (B[now] == -1) {
                B[now] = j;
            } else {
                // If the node has already been reached, calculate the answer
                cnt = j;
                break;
            }
        }

        // If the simulation has not reached the end, calculate the answer
        if (j < K) {
            long tmp;
            tmp = (K - B[now]) % (cnt - B[now]);

            // Move to the final node
            for (long i = 0; i < tmp; i++) {
                now = (int) A[now];
            }
        }

        // Print the answer
        System.out.println(now);
        scanner.close();
    }
}
// <END-OF-CODE>
