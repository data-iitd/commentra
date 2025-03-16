import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input values
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N + 1];
        int[] B = new int[200100];
        Arrays.fill(B, -1);
        int now = 1;
        int cnt = 0;

        // Read array A
        for (int i = 0; i < N; i++) {
            A[i + 1] = sc.nextInt();
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

