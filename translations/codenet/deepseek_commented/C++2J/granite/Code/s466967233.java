
import java.util.*;
import java.io.*;

class s466967233 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N+1];
        int[] B = new int[N+1]; // Array to track visited nodes
        int now = 1; // Starting node
        int cnt = 0; // Counter for cycle detection
        for(int i = 1; i <= N; i++){
            A[i] = sc.nextInt(); // Read the sequence of nodes
        }
        Arrays.fill(B, -1); // Initialize all nodes as unvisited
        B[1] = 0; // Mark the starting node
        for(int j = 1; j <= K; j++){
            now = A[now]; // Move to the next node
            if(B[now] == -1){
                B[now] = j; // Mark the node as visited
            }else{
                cnt = j; // Record the cycle start
                break; // Exit the loop as cycle is detected
            }
        }
        if(j < K){
            int tmp = (K - B[now]) % (cnt - B[now]); // Calculate remaining steps
            for (int j = 0; j < tmp; j++)
            {
                now = A[now]; // Move to the position after K steps
            }
        }
        System.out.println(now); // Output the final position
        sc.close();
    }
}

