
import java.util.*;
import java.io.*;

class s466967233 {
    public static void main(String[] args) {
        // Initialize variables
        int N, K;
        int[] A = new int[200100];
        int[] B = new int[200100];
        int now = 1;
        int cnt = 0;

        // Read input values
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        // Read array A
        for (int i = 0; i < N; i++) {
            A[i + 1] = sc.nextInt();
        }

        // Initialize B array with -1
        for (int i = 0; i < 200100; i++) {
            B[i] = -1;
        }

        // B[1] is always 0
        B[1] = 0;

        // Simulation of the algorithm
        int j;
        for (j = 1; j <= K; j++) {
            // Move to the next node
            now = A[now];

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
            int tmp;
            tmp = (K - B[now]) % (cnt - B[now]);

            // Move to the final node
            for (int j = 0; j < tmp; j++) {
                now = A[now];
            }
        }

        // Print the answer
        System.out.println(now);
    }
}
