import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements from user input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        // Read N integers from user input and store them in a list P
        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = sc.nextInt();
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
        int max_len = 1;
        
        // Iterate through the array to find the longest increasing subsequence
        for (int i = 0; i < N; i++) {
            if (a[i] < a[i + 1]) {
                tmp += 1;  // Increase the temporary length if the sequence is increasing
                max_len = Math.max(max_len, tmp);  // Update the maximum length found
            } else {
                tmp = 1;  // Reset temporary length if the sequence is not increasing
        }
        
        // Calculate the answer as the total elements minus the length of the longest subsequence
        int ans = N - max_len;
        System.out.println(ans);
    }
}

