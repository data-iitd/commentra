import java.util.Scanner;

public class Main {
    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        // Initialize the result variable to store the maximum score
        int res = 0;
        
        // Recursive function to explore combinations of numbers
        void rec(int[] A) {
            // Base case: if the length of A equals N, calculate the score
            if (A.length == N) {
                int ans = 0;
                // Check each query to see if it contributes to the score
                for (int i = 0; i < Q; i++) {
                    if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                        ans += d[i];  // Add the score from the query if it matches
                    }
                }
                // Update the maximum score found
                res = Math.max(res, ans);
                return;
            }
            
            // Determine the starting point for the next number to be added
            int last_max = 1;
            if (A.length > 0) {
                last_max = A[A.length - 1];
            }
            
            // Iterate through possible values to add to the combination
            for (int i = last_max; i <= M; i++) {
                rec(A);  // Recursively call with the new number added to A
            }
        }
        
        // Start the recursive exploration with an empty list
        rec(new int[0]);
        
        // Print the maximum score found
        System.out.println(res);
    }
    
    public static void main(String[] args) {
        // Generator function to iterate through input tokens
        Scanner sc = new Scanner(System.in);
        Iterator<String> tokens = new Iterator<String>() {
            @Override
            public boolean hasNext() {
                return sc.hasNext();
            }
            
            @Override
            public String next() {
                return sc.next();
            }
        };
        
        // Read the values of N, M, and Q from input
        int N = Integer.parseInt(tokens.next());
        int M = Integer.parseInt(tokens.next());
        int Q = Integer.parseInt(tokens.next());
        
        // Initialize lists to hold the query parameters
        int[] a = new int[Q];
        int[] b = new int[Q];
        int[] c = new int[Q];
        int[] d = new int[Q];
        
        // Read the query parameters from input
        for (int i = 0; i < Q; i++) {
            a[i] = Integer.parseInt(tokens.next());
            b[i] = Integer.parseInt(tokens.next());
            c[i] = Integer.parseInt(tokens.next());
            d[i] = Integer.parseInt(tokens.next());
        }
        
        // Call the solve function with the parsed input
        solve(N, M, Q, a, b, c, d);
    }
}

