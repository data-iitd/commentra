import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements N and the threshold K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Read the two arrays of integers As and Fs
        int[] As = new int[N];
        int[] Fs = new int[N];
        for (int i = 0; i < N; i++) {
            As[i] = scanner.nextInt();
        }
        for (int i = 0; i < N; i++) {
            Fs[i] = scanner.nextInt();
        }
        
        // Sort the As array in ascending order
        Arrays.sort(As);
        // Sort the Fs array in descending order
        Arrays.sort(Fs);
        for (int i = 0; i < N / 2; i++) {
            int temp = Fs[i];
            Fs[i] = Fs[N - 1 - i];
            Fs[N - 1 - i] = temp;
        }
        
        // Create an array to hold the scores calculated from As and Fs
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            // Calculate the score for each pair of As and Fs
            scores[i] = As[i] * Fs[i];
        }
        
        // Sort the scores in descending order
        Arrays.sort(scores);
        for (int i = 0; i < N / 2; i++) {
            int temp = scores[i];
            scores[i] = scores[N - 1 - i];
            scores[N - 1 - i] = temp;
        }
        
        // Initialize binary search boundaries
        int ok = scores[0]; // The maximum possible score
        int ng = -1;        // The minimum possible score
        
        // Perform binary search to find the maximum score that can be achieved
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2; // Calculate the midpoint of the current range
            
            boolean isOK = true; // Flag to check if the current mid is achievable
            int k = K; // Remaining threshold to adjust scores
            for (int i = 0; isOK && i < N; i++) {
                // If the current score exceeds mid, calculate how much we need to reduce
                if (As[i] * Fs[i] > mid) {
                    k -= As[i] - mid / Fs[i];
                }
                // If we exceed the allowed threshold, mark isOK as false
                if (k < 0) {
                    isOK = false;
                }
            }
            
            // Adjust binary search boundaries based on whether mid is achievable
            if (isOK) {
                ok = mid; // If achievable, move the upper boundary
            } else {
                ng = mid; // If not achievable, move the lower boundary
            }
        }
        
        // Print the maximum achievable score
        System.out.println(ok);
    }
}
