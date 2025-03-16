import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[200100];
        long[] B = new long[200100]; // Array to track visited nodes
        for (int i = 0; i < 200100; i++) {
            B[i] = -1; // Initialize all nodes as unvisited
        }
        
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong(); // Read the sequence of nodes
        }
        
        int now = 1; // Starting node
        long cnt = 0; // Counter for cycle detection
        B[1] = 0; // Mark the starting node
        
        long j;
        for (j = 1; j <= K; j++) {
            now = (int) A[now]; // Move to the next node
            if (B[now] == -1) {
                B[now] = j; // Mark the node as visited
            } else {
                cnt = j; // Record the cycle start
                break; // Exit the loop as cycle is detected
            }
        }
        
        if (j < K) {
            long tmp = (K - B[now]) % (cnt - B[now]); // Calculate remaining steps
            for (long k = 0; k < tmp; k++) {
                now = (int) A[now]; // Move to the position after K steps
            }
        }
        
        System.out.println(now); // Output the final position
        scanner.close();
    }
}
// <END-OF-CODE>
