import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input: N, C, K
        int N = scanner.nextInt();
        int C = scanner.nextInt();
        int K = scanner.nextInt();

        // Initialize array t of size N
        int[] t = new int[N];

        // Read input: t[i] for i from 0 to N-1
        for (int i = 0; i < N; i++) {
            t[i] = scanner.nextInt();
        }

        // Sort array t in ascending order
        Arrays.sort(t);

        // Initialize variables: answer counter ans, counter cnt, and end index end
        int ans = 1;
        int cnt = 1;
        int end = t[0] + K;

        // Iterate through array t from index 1 to N-1
        for (int i = 1; i < N; i++) {
            // If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
            if (cnt < C && t[i] <= end) {
                cnt++;
            } else {
                // Reset counter cnt and update end index end to the current element t[i] plus K
                cnt = 1;
                end = t[i] + K;
                // Increment answer counter ans
                ans++;
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}

