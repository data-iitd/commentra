import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the values of N, M, and Q from input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();
        
        // Initialize lists to hold the query parameters
        int[] a = new int[Q];
        int[] b = new int[Q];
        int[] c = new int[Q];
        int[] d = new int[Q];
        
        // Read the query parameters from input
        for (int i = 0; i < Q; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }
        
        // Call the solve function with the parsed input
        solve(N, M, Q, a, b, c, d);
    }
    
    // Recursive function to explore combinations of numbers
    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        // Initialize the result variable to store the maximum score
        int res = 0;
        
        // Recursive function to explore combinations of numbers
        void rec(List<Integer> A) {
            // Base case: if the length of A equals N, calculate the score
            if (A.size() == N) {
                int ans = 0;
                // Check each query to see if it contributes to the score
                for (int i = 0; i < Q; i++) {
                    if (A.get(b[i] - 1) - A.get(a[i] - 1) == c[i]) {
                        ans += d[i];  // Add the score from the query if it matches
                    }
                }
                // Update the maximum score found
                res = Math.max(res, ans);
                return;
            }
            
            // Determine the starting point for the next number to be added
            int last_max = 1 if A.size() == 0 else A.get(A.size() - 1);
            
            // Iterate through possible values to add to the combination
            for (int i = last_max; i <= M; i++) {
                rec(A.add(i));  // Recursively call with the new number added to A
        }
        
        // Start the recursive exploration with an empty list
        rec(new ArrayList<>());
        
        // Print the maximum score found
        System.out.println(res);
    }
}

