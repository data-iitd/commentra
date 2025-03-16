
import java.util.Scanner;

public class atcoder_AGC024_B{
    public static void main(String[] args) {
        // Read the number of elements from user input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        
        // Read N integers from user input and store them in an array P
        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = scanner.nextInt();
        }
        
        // Call the editorial function to process the input
        editorial(N, P);
    }

    public static void editorial(int N, int[] P) {
        // If there is only one element, the answer is 0 (no removals needed)
        if (N == 1) {
            System.out.println(0);
            return;
        }
        
        // Create an array to store the positions of elements in P
        int[] a = new int[N + 1];
        
        // Fill the array 'a' with the indices of the elements in P
        for (int i = 0; i < N; i++) {
            a[P[i]] = i;
        }
        
        // Initialize temporary length and maximum length variables
        int tmp = 1;
        int maxLen = 1;
        
        // Iterate through the array to find the longest increasing subsequence
        for (int i = 1; i < N; i++) {
            if (a[i] < a[i + 1]) {
                tmp++;  // Increase the temporary length if the sequence is increasing
                maxLen = Math.max(maxLen, tmp);  // Update the maximum length found
            } else {
                tmp = 1;  // Reset temporary length if the sequence is not increasing
            }
        }
        
        // Calculate the answer as the total elements minus the length of the longest subsequence
        int ans = N - maxLen;
        System.out.println(ans);
    }

    public static void WA(int N, int[] P) {
        // Initialize temporary length and answer variables
        int tmp = 0;
        int ans = 0;
        
        // Iterate through the array P to find the longest consecutive subsequence
        for (int i = 0; i < N; i++) {
            // Check if the current element is consecutive to the previous one
            if (i == 0 || P[i - 1] + 1 == P[i]) {
                tmp++;  // Increase temporary length for consecutive elements
            } else {
                ans = Math.max(ans, tmp);  // Update the answer with the maximum found
                tmp = 1;  // Reset temporary length for a new sequence
            }
        }
        
        // Print the result as the total elements minus the longest consecutive subsequence
        System.out.println(N - ans);
    }
}

Translate the above Java code to C++ and end with comment "